#ifndef _INSERTSORT_HPP
#define _INSERTSORT_HPP
/**
 * @file insertionSort.hpp
 * @author antaresz (antaresz1026@gmail.com)
 * @brief 插入排序
 * @version 1.0
 * @date 2024-09-13
 * 
 * @copyright Copyright (c) 2024 antaresz
 * 
 * @par 修改日志:
 * <table>
 * <tr><th>Date       <th>Version <th>Author <th>Description
 * <tr><td>2024-09-13 <td>1.0     <td>antaresz    <td>增添注释
 * </table>
 */
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <boost/log/trivial.hpp>
/// @brief insertionSort类
class insertionSort {
public:
    /// @brief 构造函数，目前置空
    insertionSort() {
    }
    /**
     * @brief 核心函数，插入排序
     * 
     * @param data 
     * @param op 
     */
    void _sort(const std::string& data, const bool& op);
private:
    /**
     * @brief 内部存储的需要排序的数组
     * 
     */
    std::vector<int> _sorted_data;
    /// @brief 对原始输入的解析
    /// @param data 
    void dataParse(const std::string& data);
};
#endif