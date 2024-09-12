#define BOOST_TEST_MODULE randomGernarateTest
#include <boost/test/included/unit_test.hpp>
#include "randomGernarate.hpp"
#include "log.hpp"

BOOST_AUTO_TEST_CASE(test_case1) {
    init_log();
    randomGernarate test("../data/randomGernarateTest.txt", 1, 100, 4, 10);
    BOOST_CHECK_EQUAL(4, test.checkLine());
}