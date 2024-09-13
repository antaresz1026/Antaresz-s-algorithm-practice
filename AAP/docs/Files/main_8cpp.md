---
title: src/main.cpp
summary: 主函数main()入口 

---

# src/main.cpp

主函数main()入口  [More...](#detailed-description)

## Functions

|                | Name           |
| -------------- | -------------- |
| int | **[main](Files/main_8cpp.md#function-main)**() |

## Detailed Description

主函数main()入口 

**Author**: antaresz ([antaresz1026@gmail.com](mailto:antaresz1026@gmail.com)) 

**Version**: 1.0 

**Date**: 2024-09-13

**Copyright**: Copyright (c) 2024 antaresz

**Par**: 修改日志:


| Date  | Version  | Author  | Description  |
|  -------- | -------- | -------- | -------- |
| 2024-09-13  | 1.0  | antaresz  | 添加注释  |

## Functions Documentation

### function main

```cpp
int main()
```




## Source code

```cpp

#include <iostream>
#include "insertionSort.hpp"
#include "log.hpp"
#include "randomGernarate.hpp"
#include "dataRead.hpp"

int main() {
    init_log();
    insertionSort sort_test;
    dataRead test("../data/randomGernarateTest.txt");
    std::string data;

    while(test >> data) {
        sort_test._sort(data, true);
        data.clear();
    }

    return 0;
}
```


-------------------------------

Updated on 2024-09-13 at 13:39:43 +0800
