#ifndef _DATAREAD_HPP
#define _DATAREAD_HPP
/**
 * @file dataRead.hpp
 * @author antaresz (antaresz1026@gmail,com)
 * @brief 读取文件数据，流式设计
 * @version 0.1
 * @date 2024-09-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <fstream>
#include <sstream>
#include "log.hpp"
#include <queue>

/**
 * @brief dataRead类
 * 
 */
class dataRead {
public:
    /**
     * @brief Construct a new data Read object
     * 
     * @param filename 
     */
    dataRead(const std::string& filename) {
        _file.open(filename);

        if (!_file.is_open()) {
            BOOST_LOG_TRIVIAL(error) << "Can't open file";
            throw std::runtime_error("无法打开文件");
        }

        std::string line;

        while (std::getline(_file, line)) {
            _lines.push(line);
        }
    }

    /**
     * @brief 操作符>>重载
     * 
     * @param line 
     * @return dataRead& 
     */
    dataRead& operator>>(std::string& line) {
        if (!_lines.empty()) {
            line = _lines.front();
            _lines.pop();
        } else {
            line.clear();
        }
        return *this;
    }

    /**
     * @brief 如果已经读取完，则返回false
     * 
     * @return true 
     * @return false 
     */
    operator bool() const {
        return !_lines.empty(); // 返回流是否仍然有效
    }
private:
    std::ifstream _file;
    std::queue<std::string> _lines;
};

#endif