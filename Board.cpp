#include <string>
#include <vector>
#include <iterator>
#include <iostream>
using namespace std;
#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;
const char ch='_';
namespace ariel {

void ariel::Board::post(unsigned int horizontal, unsigned int vertical, Direction d, const std::string &message){
    update(horizontal,vertical,d,message.size());

    if(d == Direction::Vertical){
       for(unsigned int j=0;j<message.length();j++){
            board.at(horizontal+j).at(vertical)=message.at(j);
        }
    }
    else{
         for(unsigned int i=0;i<message.length();i++){
            board.at(horizontal).at(vertical+i)=message.at(i);
        }
    }
}
std::string ariel::Board::read(unsigned int horizontal, unsigned int vertical, Direction d, unsigned int length) {
  string mymessage="";
  update(horizontal,vertical,d,length);

    if(d == Direction::Vertical){
        for(unsigned int j=0;j<length;j++){
            mymessage=mymessage+board.at(horizontal+j).at(vertical);
        }
    }
    else{
         for(unsigned  i=0;i<length;i++){
            mymessage=mymessage+board.at(horizontal).at(vertical+i);
        }
    }
 return mymessage;
}

void Board::update(unsigned int horizontal, unsigned int vertical, Direction d, unsigned int len){
        if(this->horizontal_start==0 && vertical_start==0 && this->horizontal_end==INT32_MAX && this->vertical_end==INT32_MAX){
             if (d == Direction::Vertical){
                this->horizontal_end=horizontal+len;
                this->vertical_end=vertical+1;
                this->horizontal_start=horizontal;
                this->vertical_end=vertical;
             }
             else{
                 this->horizontal_end=horizontal+1;
                this->vertical_end=vertical+len;
                this->horizontal_start=horizontal;
                this->vertical_start=vertical;
             }
        }

        else{
            this->vertical_start=min(this->vertical_start, vertical);
            this->horizontal_start=min(this->horizontal_start, horizontal);

            if(d == Direction::Vertical){
                this->vertical_end=max(this->vertical_end, vertical+1);
                this->horizontal_end=max(this->horizontal_end, horizontal+len+1);
            }
            else{
                
                this->vertical_end= max(this->vertical_end, vertical+len+1);
                this->horizontal_end=max(this->horizontal_end, horizontal+1);
            }
            this->vertical_start=min(this->vertical_start, vertical);
            this->horizontal_start=min(this->horizontal_start, horizontal);
             }

            this-> board.resize(this->horizontal_end);
             for(unsigned int i=0; i < this->horizontal_end; i++){
                board.at(i).resize(this->vertical_end,ch);
        }
}
void ariel::Board::show() {
  for(unsigned int i=horizontal_start ;i<this->horizontal_end;i++){
    for(unsigned int j=vertical_start;j<this->vertical_end;j++){
      cout << this->board.at(i).at(j);
    }

  }
  
}
}