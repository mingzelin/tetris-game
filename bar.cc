#include <vector>
#include "bar.h"
#include "cell.h"

Bar:: Bar(std::vector<Cell*> lst):Block{lst} {}
Bar:: ~Bar(){}

Block* Bar:: copy()const{
    return new Bar(list);
}

Cell* Bar:: getMinMaxH(int x)const{
    int max = list[1]->getr();
    int min = list[1]->getr();
    Cell* ma = list[1];
    Cell* mi = list[1];
    for(int i=0; i<list.size();i++){
        if(! list[i])continue;
        if(list[i]->getr()>= max){
            max = list[i]->getr();
            ma = list[i];
        }else if(list[i]->getr()<= min){
            min = list[i]->getr();
            mi = list[i];
        }
    }
    if(x) return ma;
    return mi;
}

Cell* Bar:: getMinMaxV(int x)const{
    int max = list[1]->getc();
    int min = list[1]->getc();
    Cell* ma = list[1];
    Cell* mi = list[1];
    for(int i=0; i<list.size();i++){
        if(! list[i])continue;
        if(list[i]->getc()>=max){
            max = list[i]->getc();
            ma = list[i];
        }else if(list[i]->getc()<= min){
            min = list[i]->getc();
            mi = list[i];
        }
    }
    if(x) return ma;
    return mi;
}

bool Bar:: isHorizontal()const{
    int maxc = getMinMaxH(1)->getc();
    int minc = getMinMaxH(0)->getc();
    if(minc == maxc) return true;
    return false;
}

bool Bar:: canRotate(int isCounter, std::vector<std::vector<Cell>>& grid){
    Cell* miV = getMinMaxV(0);
    Cell* maxH = getMinMaxH(1);
    if(isHorizontal()){
        int r = maxH->getr();
        int c = maxH->getc();
        if((c+3)>11) return false;
        if(grid[r][c+1].getState()||
           grid[r][c+2].getState()||
           grid[r][c+3].getState()) return false;
    }else{
        int r = miV->getr();
        int c = miV->getc();
        if((r-3)<0) return false;
        if(grid[r-1][c].getState()||
           grid[r-2][c].getState()||
           grid[r-3][c].getState()) return false;
    }
    return true;
}

int Bar:: rotate(std::vector<std::vector<Cell>>& grid){
    Cell* miV = getMinMaxV(0);
    Cell* maxH = getMinMaxH(1);
    int r,c;
    char k;
    if(isHorizontal()&& canRotate(1, grid)){
        for(int i=0; i<list.size(); i++){
            if((!list[i])||(list[i]->getr()==maxH->getr())) continue;
            list[i]->changeState(0);
            r = list[i]->getr();
            c = list[i]->getc();
            k = list[i]->getKind();
            if(list[i]->getr()==maxH->getr()-1){
                list[i] = &grid[maxH->getr()][c + 1];
            }else if(list[i]->getr()==maxH->getr()-2){
                list[i] = &grid[maxH->getr()][c + 2];
            }else {
                list[i] = &grid[maxH->getr()][c + 3];
            }
            list[i]->changeState(1);
            list[i]->changeKind(k);
        }
        return 1;
    }else if(canRotate(1, grid)){
        for(int i=0; i<list.size(); i++){
            if((!list[i])||(list[i]->getc()==miV->getc())) continue;
            list[i]->changeState(0);
            r = list[i]->getr();
            c = list[i]->getc();
            k = list[i]->getKind();
            if(list[i]->getc()==miV->getc()+1){
                list[i] = &grid[r-1][miV->getc()];
            }else if(list[i]->getc()==miV->getc()+2){
                list[i] = &grid[r-2][miV->getc()];
            }else {
                list[i] = &grid[r-3][miV->getc()];
            }
            list[i]->changeState(1);
            list[i]->changeKind(k);
        }
        return 1;
    }
    return 0;
}

int Bar:: crotate(std::vector<std::vector<Cell>>& grid){
    return rotate(grid);
}


