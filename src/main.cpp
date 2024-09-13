/**
 * @file main.cpp
 * @author antaresz (antaresz1026@gmail.com)
 * @brief 主函数main()入口
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