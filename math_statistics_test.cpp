
#include "iostream"

#include "math_statistics.h"

#define BOOST_TEST_DYN_LINK

#include <vector>

#include <boost/test/unit_test.hpp>

namespace chaos
{
    BOOST_AUTO_TEST_SUITE(Chaos)

    // NOTE WE NEED TO ADD CASES FOR NaN and Infinty

    BOOST_AUTO_TEST_CASE(Math_Stats, * boost::unit_test::tolerance(0.00001))
    {
        std::vector<double> c = {3.5, 2.9, 7.21, 3.666, 9.5, 23, 12.5, 14.8, 6.7, 11.33};

        double m_v1 = 0, m_v2 = 0, m_v3 = 0;
        m_v1 = chaos::math::statistics::mean_v1(c);
        BOOST_TEST( m_v1 == 9.5106 );
        m_v2 = chaos::math::statistics::mean_v2(c);
        BOOST_TEST( m_v2 == 9.5106 );
        m_v3 = chaos::math::statistics::mean_v3(c, c.size());
        BOOST_TEST( m_v3 == 9.5106 );

        double mean = chaos::math::statistics::mean(c);
        BOOST_TEST( mean == 9.5106 );
        mean = chaos::math::statistics::mean(c, c.size());
        BOOST_TEST( mean == 9.5106 );

        double std = 0, std_v1 = 0, std_v2 = 0,  std_v3 = 0, std_p = 0 , std_s = 0;
        std_v1 = chaos::math::statistics::stdev_v1(c);
        BOOST_TEST( std_v1 == 5.910731 );
        std_v2 = chaos::math::statistics::stdev_v2(c);
        BOOST_TEST( std_v2 == 5.910731 );
        std_v3 = chaos::math::statistics::stdev_v3(c);
        BOOST_TEST( std_v3 == 6.230458 );
        std_p = chaos::math::statistics::stdev_p(c);
        BOOST_TEST( std_p == 5.910731 );
        std_p = chaos::math::statistics::stdev_p(c, c.size());
        BOOST_TEST( std_p == 5.910731 );
        std_s = chaos::math::statistics::stdev_s(c);
        BOOST_TEST( std_s == 6.230458 );
        std_s = chaos::math::statistics::stdev_s(c, c.size());
        BOOST_TEST( std_s == 6.230458 );

        double skew = chaos::math::statistics::skewness(c);
        BOOST_TEST( skew == .917789 );

        double kurt = chaos::math::statistics::kurtosis(c);
        BOOST_TEST( kurt == .150692 );

        chaos::math::statistics::moments(c, mean, std, skew, kurt);
        BOOST_TEST( mean == 9.5106 );
        BOOST_TEST( std == 5.91073 );
        BOOST_TEST( skew == .917789 );
        BOOST_TEST( kurt == .150692);
    }

    BOOST_AUTO_TEST_CASE(Math_Basic)
    {
        std::vector<double> c = {3.5, 2.9, 7.21, 3.666, 9.5, 23, -12.5, 14.8, 6.7, 11.33};

        double max = chaos::math::statistics::max_element(c);
        BOOST_TEST( max == 23 );
        double min = chaos::math::statistics::min_element(c);
        BOOST_TEST( min == -12.5 );

        double neg = chaos::math::statistics::get_sign(-23.66);
        BOOST_TEST( neg == -1 );
        double pos = chaos::math::statistics::get_sign(15.337);
        BOOST_TEST( pos == 1 );
        double zero = chaos::math::statistics::get_sign(0);
        BOOST_TEST( zero == 0 );

        BOOST_CHECK( chaos::math::statistics::is_double_equal(7.299999999, 7.299999999) );
    }

    BOOST_AUTO_TEST_CASE(Math_RollingWindow)
    {
        chaos::math::statistics::RollingWindow rw(10, true);
        rw.add(3.5);
        rw.add(2.9);
        rw.add(7.21);
        rw.add(3.666);
        BOOST_TEST(rw.get_last_value(), 3.66 );
        rw.add(9.5);
        rw.add(23);
        rw.add(12.5);
        BOOST_TEST(rw.get_percent_buffered(), .7 );
        rw.add(14.8);
        rw.add(6.7);
        double mid = 0;
        BOOST_CHECK( rw.get_average(mid) == false );
        rw.add(11.33);
        BOOST_CHECK( rw.get_average(mid) );
        BOOST_TEST( mid == 9.5106 );
        BOOST_TEST( rw.get_min(), -12.5 );
        BOOST_TEST( rw.get_max(), 23 );
    }

    BOOST_AUTO_TEST_CASE(Math_RollingWindow_withMoments, * boost::unit_test::tolerance(0.00001))
    {
        chaos::math::statistics::RollingWindow rw(10);
        rw.add(3.5);
        rw.add(2.9);
        rw.add(7.21);
        rw.add(3.666);
        BOOST_TEST(rw.get_last_value(), 3.66 );
        rw.add(9.5);
        rw.add(23);
        rw.add(12.5);
        BOOST_TEST(rw.get_percent_buffered(), .7 );
        rw.add(14.8);
        rw.add(6.7);
        double mid = 0, std = 0, sk = 0, ku = 0, mm = 0;
        BOOST_CHECK( rw.get_average(mid) == false );
        rw.add(11.33);
        BOOST_CHECK( rw.get_average(mid) );
        BOOST_CHECK( rw.get_stdev(std) );
        BOOST_CHECK( rw.get_skew(sk) );
        BOOST_CHECK( rw.get_kurtosis(ku) );
        BOOST_CHECK( rw.get_min_max_vol(mm) );
        BOOST_TEST( mid == 9.5106 );
        BOOST_TEST( std == 5.91073 );
        BOOST_TEST( sk == .917789 );
        BOOST_TEST( ku == .150692);
        BOOST_TEST( mm, 5.91073 );
        BOOST_TEST( rw.get_min(), -12.5 );
        BOOST_TEST( rw.get_max(), 23 );

    }

    BOOST_AUTO_TEST_SUITE_END()
}
