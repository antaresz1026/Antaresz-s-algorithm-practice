#define BOOST_TEST_MODULE insertSortTest
#include <boost/test/included/unit_test.hpp>
#include "randomGernarate.hpp"
#include "log.hpp"
#include "dataRead.hpp"
#include "insertionSort.hpp"
BOOST_AUTO_TEST_CASE(test_case1) {
    init_log();
    std::string line;

    dataRead test("../data/randomGernarateTest.txt");

    test >> line;
    std::cout << line << "\n";
}

BOOST_AUTO_TEST_CASE(test_case2) {
    init_log();
    insertionSort sort_test;
    dataRead test("../data/randomGernarateTest.txt");
    std::string data;

    while(test >> data) {
        sort_test._sort(data, true);
    }
}