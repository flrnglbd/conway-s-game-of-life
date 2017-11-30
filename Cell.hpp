#ifndef CELL_H
#define CELL_H

#include <iostream>
#include "Position.hpp"

using namespace std;

class Cell {
public:
    Position pos;

    Cell();
    Cell(int x, int y);
    bool isAlive() const;
    void born();
    void die();

private:
    bool alive;

};

#endif // CELL_H
