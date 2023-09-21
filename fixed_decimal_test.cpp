
#include "iostream"

#include "fixed_decimal.h"

#define BOOST_TEST_DYN_LINK
// Note this should only be declared once
#define BOOST_TEST_MODULE Chaos

#include <boost/test/unit_test.hpp>

namespace chaos
{
    BOOST_AUTO_TEST_SUITE(Chaos)

    // NOTE WE NEED TO ADD CASES FOR NaN and Infinty

    BOOST_AUTO_TEST_CASE(FixedDecimal_Constructer1)
    {
        chaos::FixedDecimal fd1(100,1);
        chaos::FixedDecimal fd2(10.0);
        chaos::FixedDecimal fd3("10");
        BOOST_CHECK( fd1 == fd2 );
        BOOST_CHECK( fd1 == fd3 );
        BOOST_CHECK( fd2 == fd3 );
        //std::cout << "fd1=" << fd1.asString() << " fd2=" << fd2.asString() << " fd3=" << fd3.asString() << std::endl;
    }

    BOOST_AUTO_TEST_CASE(FixedDecimal_Constructer2)
    {
        chaos::FixedDecimal fd1(999,1);
        chaos::FixedDecimal fd2(99.9);
        chaos::FixedDecimal fd3("99.9");
        BOOST_CHECK( fd1 == fd2 );
        BOOST_CHECK( fd1 == fd3 );
        BOOST_CHECK( fd2 == fd3 );
    }

    BOOST_AUTO_TEST_CASE(FixedDecimal_Constructer3)
    {
        chaos::FixedDecimal fd1(9999999990001,3);
        chaos::FixedDecimal fd2(9999999990.001);
        chaos::FixedDecimal fd3("9999999990.001");
        BOOST_CHECK( fd1 == fd2 );
        BOOST_CHECK( fd1 == fd3 );
        BOOST_CHECK( fd2 == fd3 );
    }

    BOOST_AUTO_TEST_CASE(FixedDecimal_Constructer4)
    {
        chaos::FixedDecimal fd1(314159265359,11);
        chaos::FixedDecimal fd2(3.14159265359);
        chaos::FixedDecimal fd3("3.14159265359");
        BOOST_CHECK( fd1 == fd2 );
        BOOST_CHECK( fd1 == fd3 );
        BOOST_CHECK( fd2 == fd3 );
    }

    BOOST_AUTO_TEST_CASE(FixedDecimal_Constructer5)
    {
        chaos::FixedDecimal fd1(99795,3);
        chaos::FixedDecimal fd2(99.7950);
        chaos::FixedDecimal fd3(99.795);
        BOOST_CHECK( fd1 == fd2 );
        BOOST_CHECK( fd2 == fd3 );
        BOOST_CHECK( fd1 == fd3 );
    }

    BOOST_AUTO_TEST_CASE(FixedDecimal_Constructer6)
    {
        chaos::FixedDecimal fd1(99,1);
        chaos::FixedDecimal fd2(9.89999999999999999999);
        chaos::FixedDecimal fd3("9.9");
        BOOST_CHECK( fd1 == fd2 );
        BOOST_CHECK( fd2 == fd3 );
        BOOST_CHECK( fd1 == fd3 );
    }

    BOOST_AUTO_TEST_CASE(FixedDecimal_Constructer7)
    {
        chaos::FixedDecimal fd1(99,1);
        chaos::FixedDecimal fd2(9.90000000000000000001);
        chaos::FixedDecimal fd3("9.9");
        BOOST_CHECK( fd1 == fd2 );
        BOOST_CHECK( fd2 == fd3 );
        BOOST_CHECK( fd1 == fd3 );
    }

    BOOST_AUTO_TEST_CASE(FixedDecimal_Constructer8)
    {
        chaos::FixedDecimal fd1(-99,1);
        chaos::FixedDecimal fd2(-9.90000000000000000001);
        chaos::FixedDecimal fd3("-9.9");
        BOOST_CHECK( fd1 == fd2 );
        BOOST_CHECK( fd2 == fd3 );
        BOOST_CHECK( fd1 == fd3 );
    }

    BOOST_AUTO_TEST_CASE(FixedDecimal_FromMethods)
    {
        chaos::FixedDecimal fd1;
        chaos::FixedDecimal fd2;
        chaos::FixedDecimal fd3(99245,3);
        fd1.from_string("99.245");
        fd2.from_double(99.245);
        BOOST_CHECK( fd1 == fd2 );
        BOOST_CHECK( fd2 == fd3 );
        BOOST_CHECK( fd1 == fd3 );
    }

    BOOST_AUTO_TEST_CASE(FixedDecimal_Serialized)
    {
        chaos::FixedDecimal fd1(99245,3);
        chaos::FixedDecimal fd2;
        fd2.from_serialized_string("99245-3");
        BOOST_CHECK( fd1 == fd2 );
    }

    BOOST_AUTO_TEST_CASE(FixedDecimal_AsSerialized)
    {
        chaos::FixedDecimal fd1(99245,3);
        chaos::FixedDecimal fd2;
        fd2.from_serialized_string("99245-3");
        BOOST_CHECK( fd1.as_serialized_string() == fd2.as_serialized_string() );
    }

    BOOST_AUTO_TEST_CASE(FixedDecimal_AsDouble)
    {
        chaos::FixedDecimal fd1(99795,3);
        chaos::FixedDecimal fd2(99.7950);
        chaos::FixedDecimal fd3(99.795);
        BOOST_CHECK( fd1.as_double() == fd2.as_double() );
        BOOST_CHECK( fd2.as_double() == fd3.as_double() );
        BOOST_CHECK( fd1.as_double() == fd3.as_double() );
    }

    BOOST_AUTO_TEST_CASE(FixedDecimal_AsString)
    {
        chaos::FixedDecimal fd1(99795,3);
        chaos::FixedDecimal fd2(99.7950);
        chaos::FixedDecimal fd3(99.795);
        BOOST_CHECK( fd1.as_string() == fd2.as_string() );
        BOOST_CHECK( fd2.as_string() == fd3.as_string() );
        BOOST_CHECK( fd1.as_string() == fd3.as_string() );
    }

    BOOST_AUTO_TEST_SUITE_END()
}
