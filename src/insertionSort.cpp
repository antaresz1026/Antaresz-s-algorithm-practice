#include "insertionSort.hpp"
#include "log.hpp"

void insertionSort::dataParse(const std::string& data) {
    std::istringstream iss(data);
    std::ostringstream oss;
    std::string number;

    while(iss >> number) {
        _sorted_data.push_back(std::stoi(number.c_str()));
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
        key = _sorted_data[j];
        i = j - 1;

        if(op) {
            while (i > -1) {
                if ( _sorted_data[i] > key) {
                    std::swap(_sorted_data[i], _sorted_data[i + 1]);
                }
                -- i;
            }            
        } else {
            while (i > -1) {
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
    _sorted_data.clear();
}