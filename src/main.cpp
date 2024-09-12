#include <iostream>
#include "insertionSort.hpp"
#include "log.hpp"
#include "randomGernarate.hpp"
#include "dataRead.hpp"

int main() {
    init_log();
    insertionSort sort_test;
    dataRead test("../data/randomGernarateTest.txt");
    std::string data;

    while(test >> data) {
        sort_test._sort(data, true);
        data.clear();
    }

    return 0;
}