

#ifndef level1_hpp
#define level1_hpp

#include "nextGenerator.h"
#include <cstdlib>
#include <iostream>
////////////
//class Cell;
//class Block;
////////////
class Level1:public NextGenerator{
    int rand_result;
    virtual Block* generateNext(std::vector<std::vector <Cell>> &grid,int &success,char &k,char &next,bool init,bool norand,std::string norandfilename) override;
public:
};


#endif /* level1_hpp */
