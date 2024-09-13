---
title: src/log.cpp
summary: 日志实现 

---

# src/log.cpp

日志实现  [More...](#detailed-description)

## Functions

|                | Name           |
| -------------- | -------------- |
| void | **[init_log](Files/log_8cpp.md#function-init-log)**()<br />设置日志级别、格式、输出地  |

## Detailed Description

日志实现 

**Author**: antaresz ([antaresz1026@gmail.com](mailto:antaresz1026@gmail.com)) 

**Version**: 1.0 

**Date**: 2024-09-13

**Copyright**: Copyright (c) 2024 antaresz

**Par**: 修改日志:


| Date  | Version  | Author  | Description  |
|  -------- | -------- | -------- | -------- |
| 2024-09-13  | 1.0  | antaresz  | 添加注释  |

## Functions Documentation

### function init_log

```cpp
void init_log()
```

设置日志级别、格式、输出地 

日志初始化 




## Source code

```cpp

#include "log.hpp"
void init_log() {
    boost::log::core::get()->set_filter(
        boost::log::trivial::severity >= boost::log::trivial::info
    );
    // 将日志输出到文件，并设置日志格式
    boost::log::add_file_log(
        boost::log::keywords::file_name = "../logs/app_%N.log",  // 日志文件名
        boost::log::keywords::rotation_size = 10 * 1024 * 1024,  // 日志文件大小限制
        boost::log::keywords::time_based_rotation = boost::log::sinks::file::rotation_at_time_point(0, 0, 0),  // 每天新建日志文件
        boost::log::keywords::format = "[%TimeStamp%] [%Severity%]: %Message%"  // 日志输出格式
    );

    // 同时在控制台输出日志
    boost::log::add_console_log(
        std::cout,
        boost::log::keywords::format = "[%TimeStamp%] [%Severity%]: %Message%"
    );

    // 添加常见属性：时间戳、日志级别等
    boost::log::add_common_attributes();
}
```


-------------------------------

Updated on 2024-09-13 at 13:39:43 +0800
