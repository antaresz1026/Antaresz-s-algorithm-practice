---
title: src/randomGernarate.cpp
summary: 随机数生成实现 

---

# src/randomGernarate.cpp

随机数生成实现  [More...](#detailed-description)

## Detailed Description

随机数生成实现 

**Author**: antaresz ([antaresz1026@gmail.com](mailto:antaresz1026@gmail.com)) 

**Version**: 1.0 

**Date**: 2024-09-13

**Copyright**: Copyright (c) 2024 antaresz

**Par**: 修改日志:


| Date  | Version  | Author  | Description  |
|  -------- | -------- | -------- | -------- |
| 2024-09-13  | 1.0  | antaresz  | 添加注释  |



## Source code

```cpp

#include "randomGernarate.hpp"
int randomGernarate::checkLine() {
    std::ifstream file(_filename);
    std::string line;
    int line_count = 0;
    
    while (std::getline(file, line)) {
        ++line_count;
    }

    return line_count;
}
```


-------------------------------

Updated on 2024-09-13 at 13:39:43 +0800
