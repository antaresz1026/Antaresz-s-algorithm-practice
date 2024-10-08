/**
 * @file insertionSort.cpp
 * @author antaresz (antaresz1026@gmail.com)
 * @brief insertionSort实现
 * @version 1.0
 * @date 2024-09-13
 * 
 * @copyright Copyright (c) 2024 antaresz
 * 
 * @par 修改日志:
 * <table>
 * <tr><th>Date       <th>Version <th>Author <th>Description
 * <tr><td>2024-09-13 <td>1.0     <td>antaresz    <td>添加注释
 * </table>
 */
#include "insertionSort.hpp"
#include "log.hpp"
/// @brief 使用字符串流输入输出
/// @param data 
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
/// @brief 插入排序
/// @param data 
/// @param op 
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