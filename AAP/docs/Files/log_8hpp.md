---
title: include/log.hpp
summary: 日志相关 

---

# include/log.hpp

日志相关  [More...](#detailed-description)

## Functions

|                | Name           |
| -------------- | -------------- |
| void | **[init_log](Files/log_8hpp.md#function-init-log)**()<br />日志初始化  |

## Detailed Description

日志相关 

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

日志初始化 

日志初始化 




## Source code

```cpp
#ifndef _LOG_HPP
#define _LOG_HPP
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
void init_log();

#endif
```


-------------------------------

Updated on 2024-09-13 at 13:39:43 +0800
