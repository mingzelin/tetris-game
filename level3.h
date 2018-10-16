
#include "nextGenerator.h"
#include <iostream>
#include <fstream>
//#include "highLevel.h"
/////////////
//class Cell;
//class Block;
/////////////


class Level3 : public NextGenerator {
    std::ifstream norandfile;
    //bool initrand;
    Block* generateNext(std::vector<std::vector <Cell>> &grid,int &success,char &k,char &next,bool init,bool norand,std::string norandfilename) override;
public:
    //Level3();
};
