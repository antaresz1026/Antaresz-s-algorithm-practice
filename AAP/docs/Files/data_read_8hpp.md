---
title: include/dataRead.hpp
summary: 读取文件数据，流式设计 

---

# include/dataRead.hpp

读取文件数据，流式设计  [More...](#detailed-description)

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[dataRead](Classes/classdata_read.md)** <br />dataRead类  |

## Detailed Description

读取文件数据，流式设计 

**Author**: antaresz (antaresz1026@gmail,com) 

**Version**: 0.1 

**Date**: 2024-09-12

**Copyright**: Copyright (c) 2024

**Par**: 修改日志:


| Date  | Version  | Author  | Description  |
|  -------- | -------- | -------- | -------- |
| 2024-09-13  | 1.0  | antaresz  | 增添注释  |



## Source code

```cpp
#ifndef _DATAREAD_HPP
#define _DATAREAD_HPP
#include <fstream>
#include <sstream>
#include "log.hpp"
#include <queue>

class dataRead {
public:
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

    dataRead& operator>>(std::string& line) {
        if (!_lines.empty()) {
            line = _lines.front();
            _lines.pop();
        } else {
            line.clear();
        }
        return *this;
    }

    operator bool() const {
        return !_lines.empty(); // 返回流是否仍然有效
    }
private:
    std::ifstream _file;
    std::queue<std::string> _lines;
};

#endif
```


-------------------------------

Updated on 2024-09-13 at 13:39:43 +0800
