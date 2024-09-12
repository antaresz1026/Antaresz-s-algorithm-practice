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