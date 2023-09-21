// This will test our uuid functions


#include "uuid.h"

#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

namespace chaos
{
    BOOST_AUTO_TEST_SUITE(Chaos)

    BOOST_AUTO_TEST_CASE(UuidTest1)
    {
        uuid_t id_1, id_2;
        chaos::generate_uuid( id_1 );
        std::string tmp = chaos::convert_uuid_to_string( id_1 );
        chaos::convert_uuid_from_string( tmp.c_str(), id_2 );
        BOOST_CHECK( chaos::compare_uuid( id_1, id_2 ) );
    }

    BOOST_AUTO_TEST_CASE(UuidTest2)
    {
        uuid_t id_1, id_2;
        chaos::generate_time_safe_uuid( id_1 );
        std::string tmp = chaos::convert_uuid_to_string( id_1 );
        chaos::convert_uuid_from_string( tmp.c_str(), id_2 );
        BOOST_CHECK( chaos::compare_uuid( id_1, id_2 ) );
    }

    BOOST_AUTO_TEST_CASE(UuidTest3)
    {
        uuid_t id_1, id_2;
        chaos::generate_time_uuid( id_1 );
        std::string tmp = chaos::convert_uuid_to_string( id_1 );
        chaos::convert_uuid_from_string( tmp.c_str(), id_2 );
        BOOST_CHECK( chaos::compare_uuid( id_1, id_2 ) );
    }

    BOOST_AUTO_TEST_CASE(UuidTest4)
    {
        uuid_t id_1, id_2;
        chaos::generate_uuid( id_1 );
        std::string tmp1 = chaos::convert_uuid_to_string( id_1 );
        chaos::convert_uuid_from_string( tmp1.c_str(), id_2 );
        std::string tmp2 = chaos::convert_uuid_to_string( id_2 );
        BOOST_CHECK( tmp1 == tmp2 );
    }

    BOOST_AUTO_TEST_SUITE_END()
}
