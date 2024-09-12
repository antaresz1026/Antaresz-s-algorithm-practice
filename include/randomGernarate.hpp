#ifndef _RANDOM_GERNARATE_HPP
#define _RANDOM_GERNARATE_HPP

#include <boost/random.hpp>
#include <fstream>
#include <iostream>
#include <boost/log/trivial.hpp>

class randomGernarate {
public:
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
    int checkLine();
private:
    boost::random::mt19937 _rng; // Mersenne Twister 引擎
    std::string _filename;
};

#endif