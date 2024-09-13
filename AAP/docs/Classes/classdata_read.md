---
title: dataRead
summary: dataRead类 

---

# dataRead



dataRead类 


`#include <dataRead.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[dataRead](Classes/classdata_read.md#function-dataread)**(const std::string & filename)<br />Construct a new data Read object.  |
| [dataRead](Classes/classdata_read.md) & | **[operator>>](Classes/classdata_read.md#function-operator>>)**(std::string & line)<br />操作符>>重载  |
| | **[operator bool](Classes/classdata_read.md#function-operator-bool)**() const<br />如果已经读取完，则返回false  |

## Public Functions Documentation

### function dataRead

```cpp
inline dataRead(
    const std::string & filename
)
```

Construct a new data Read object. 

**Parameters**: 

  * **filename** 


### function operator>>

```cpp
inline dataRead & operator>>(
    std::string & line
)
```

操作符>>重载 

**Parameters**: 

  * **line** 


**Return**: [dataRead](Classes/classdata_read.md)& 

### function operator bool

```cpp
inline operator bool() const
```

如果已经读取完，则返回false 

**Return**: 

  * true 
  * false 


-------------------------------

Updated on 2024-09-13 at 13:39:43 +0800