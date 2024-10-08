#ifndef _RANDOM_GERNARATE_HPP
#define _RANDOM_GERNARATE_HPP
/**
 * @file randomGernarate.hpp
 * @author antaresz (antaresz1026@gmail.com)
 * @brief 随机数生成
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
#include <boost/random.hpp>
#include <fstream>
#include <iostream>
#include <boost/log/trivial.hpp>
/// @brief randomGernarate类
class randomGernarate {
public:
    /// @brief 构造函数，向提供的文件名中写入随机数
    /// @param filename 
    /// @param min 
    /// @param max 
    /// @param row 
    /// @param col 
    randomGernarate(std::string filename, int min, int max, int row, int col) : _filename(filename) {
        boost::random::uniform_int_distribution<> dist(min, max);
        std::ofstream outFile(filename);

        if (!outFile.is_open()) {
            BOOST_LOG_TRIVIAL(error) << "Can't open file\n";
        }

        // 生成随机数并写入文件
        for (int i = 0; i < row; i++) {
            for (int j = 0;j < col; j++) {
                int random_number = dist(_rng);

                outFile << random_number << " ";
            }

            if (i != row - 1) {
                outFile << "\n";
            }
            
        }

        outFile.close(); // 关闭文件
        BOOST_LOG_TRIVIAL(info) << "Random numbers gernarated successfully!";
    }
    /**
     * @brief 检查行数
     * 
     * @return int 
     */
    int checkLine();
private:
    /**
     * @brief 随机数引擎
     * 
     */
    boost::random::mt19937 _rng; // Mersenne Twister 引擎
    /**
     * @brief 文件名
     * 
     */
    std::string _filename;
};

#endif