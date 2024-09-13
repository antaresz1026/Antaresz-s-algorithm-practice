/**
 * @file randomGernarate.cpp
 * @author antaresz (antaresz1026@gmail.com)
 * @brief 随机数生成实现
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
#include "randomGernarate.hpp"
/// @brief 返回文件行数
/// @return 
int randomGernarate::checkLine() {
    std::ifstream file(_filename);
    std::string line;
    int line_count = 0;
    
    while (std::getline(file, line)) {
        ++line_count;
    }

    return line_count;
}