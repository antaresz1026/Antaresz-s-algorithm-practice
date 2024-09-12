#include "insertionSort.hpp"
#include "log.hpp"

void insertionSort::dataParse(const std::string& data) {
    std::istringstream iss(data);
    std::ostringstream oss;
    int number;

    while(iss >> number) {
        _sorted_data.push_back(number);
    }
    oss << "Readed nums (";

    for (int number : _sorted_data) {
        oss << number << " ";
    }

    oss << ")\n";

    BOOST_LOG_TRIVIAL(trace) << oss.str();
}

void insertionSort::_sort(const std::string& data, const bool& op) {   
    std::ostringstream oss;
    dataParse(data);

    try {
        _sorted_data.at(1);
    } catch (const std::out_of_range &e) {
        std::cerr << "[ERROR]: " << e.what() << "\n";
    }
    for (int i = 0, j = 1, key;j < _sorted_data.size();j++) {
        key = j;
        i = j - 1;

        if(op) {
            while (i > 0) {
                if ( _sorted_data[i] > _sorted_data[key]) {
                    std::swap(_sorted_data[i], _sorted_data[key]);
                }
                -- i;
            }            
        } else {
            while (i > 0) {
                if (_sorted_data[i] < _sorted_data[key]) {
                    std::swap(_sorted_data[i], _sorted_data[key]);
                }
                -- i;
            }            
        }

        oss << "Processing nums (";

        for (int number : _sorted_data) {
            oss << number << " ";
        }

        oss << ")\n";        
        BOOST_LOG_TRIVIAL(trace) << oss.str();
        oss.clear();
    }

    oss << "Processing nums (";

    for (int number : _sorted_data) {
        oss << number << " ";
    }

    oss << ")\n";        
    BOOST_LOG_TRIVIAL(info) << oss.str();
    oss.clear();
}