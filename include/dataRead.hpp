#ifndef _DATAREAD_HPP
#define _DATAREAD_HPP

#include <fstream>
#include <sstream>
#include "log.hpp"
#include <queue>

class dataRead {
public:
    // 构造函数，打开文件
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

    // 重载 >> 操作符，用于提取每一行数据
    dataRead& operator>>(std::string& line) {
        if (!_lines.empty()) {
            line = _lines.front();
            _lines.pop();
        } else {
            // 如果到达文件末尾，设置文件的 failbit
            _file.setstate(std::ios::failbit);
        }
        return *this;
    }

        // 检查流是否处于有效状态
    operator bool() const {
        return !_file.fail(); // 返回流是否仍然有效
    }

    // 检查文件是否结束
    bool eof() const {
        return _lines.empty();
    }
private:
    std::ifstream _file;
    std::queue<std::string> _lines;
};

#endif