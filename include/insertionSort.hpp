#ifndef _INSERTSORT_HPP
#define _INSERTSORT_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <boost/log/trivial.hpp>

class insertionSort {
public:
    insertionSort() {
    }
    void _sort(const std::string& data, const bool& op);
private:
    std::vector<int> _sorted_data;
    void dataParse(const std::string& data);
};
#endif