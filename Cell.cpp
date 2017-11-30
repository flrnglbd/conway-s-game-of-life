#include <iostream>
#include "Cell.hpp"

Cell::Cell() {
    this->alive = false;
}

Cell::Cell(int x, int y) {
    this->pos.x = x;
    this->pos.y = y;
}

bool Cell::isAlive() const {
    return this->alive;
}

void Cell::born() {
    this->alive = true;
}

void Cell::die() {
    this->alive = false;
}
