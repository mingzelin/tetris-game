#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include "observer.h"
#include "window.h"
class Board;
class Cell;
class Block;
class GraphicsDisplay: public Observer {
    Xwindow w;
    
public:
    GraphicsDisplay();
    void hint(Block* b_hint);
    void notify(Board &b) override;
};
#endif

