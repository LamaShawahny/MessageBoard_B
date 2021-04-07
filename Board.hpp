#pragma once
#include <vector>
#include <string>
#include "Direction.hpp"
namespace ariel{
    class Board{
    private:
            std:: vector<std::vector<char>> board;
            unsigned int horizontal_start=0;
            unsigned int horizontal_end=INT32_MAX;
            unsigned int vertical_start=0;
            unsigned int vertical_end=INT32_MAX;
            void update(unsigned int horizontal, unsigned int vertical, Direction d, unsigned int len);
    public:
        Board() {
            board=std:: vector<std:: vector<char>>(0, std:: vector<char>(0,'_'));
        };
        void post(unsigned int horizontal, unsigned int vertical, Direction d, const std::string &message);
        std::string read(unsigned int horizontal, unsigned int vertical, Direction d, unsigned int length);
        void show();
    };
}