#ifndef _LOG_HPP
#define _LOG_HPP
/**
 * @file log.hpp
 * @author antaresz (antaresz1026@gmail.com)
 * @brief 日志相关
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
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
/// @brief 日志初始化
void init_log();

#endif