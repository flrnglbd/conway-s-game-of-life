
#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>

#include "Cell.hpp"

#define LENGHT 10000
#define N 100
#define SIZE 10
#define FRAME_LIMIT 10

void createCisQueenBee(Cell mat[]);

void displayMatricePosition(Cell mat[]) {
    for(int i = 0; i < LENGHT; i++) {
        if(i % N == 0) {
            std::cout << "" << '\n';
        }
        std::cout << "{" << mat[i].pos.x << ", " << mat[i].pos.y  << "}";
    }
}

void displayCells(Cell mat[]) {
    for(int i = 0; i < LENGHT; i++) {
        if(i % N == 0) {
            std::cout << "" << '\n';
        }
        std::cout << "{" << mat[i].isAlive() << "}";
    }
    std::cout << '\n';
}

int countNeighbours(Cell cell, Cell mat[]) {
    int count = 0;
    Cell currentCell;
    int index;

    for(int j = -1; j <= 1; j++) {
        for(int i = -1; i <= 1; i++) {
            index = (cell.pos.y+j) * N + cell.pos.x + i;
            if(cell.pos.y+j >= 0 && cell.pos.y+j <= N-1 && cell.pos.x + i >= 0 && cell.pos.x + i <= N - 1) {
                currentCell = mat[index];

                if(currentCell.isAlive() && (currentCell.pos.x != cell.pos.x || currentCell.pos.y != cell.pos.y)) {
                    count++;
                }
            }
        }
    }
    return count;
}

Cell* getCelluleAt(int x, int y, Cell mat[]) {
    return &mat[(y) * N + x];
}

void nextStep(Cell mat[], Cell matNext[]) {
    for(int i = 0; i < LENGHT; i++) {
        int neighbours = countNeighbours(mat[i], mat);
        if(mat[i].isAlive()) {
            if(neighbours < 2 || neighbours > 3) {
                matNext[i].die();
            }
        } else {
            if(neighbours == 3) {
                matNext[i].born();
            }
        }
    }
}

void giveLife(Cell mat[]) {
    srand(time(NULL));

//    for(int i = 0; i < LENGHT; i++) {
//        int random = rand() % 10 + 1;
//        if(random % 2 == 0) {
//            mat[i].born();
//        } else {
//            mat[i].die();
//        }
//    }

    createCisQueenBee(mat);

}

void createCisQueenBee(Cell mat[]) {
    getCelluleAt(42, 54, mat)->born();
    getCelluleAt(42, 55, mat)->born();
    getCelluleAt(43, 54, mat)->born();
    getCelluleAt(43, 55, mat)->born();

    getCelluleAt(47, 54, mat)->born();

    getCelluleAt(48, 53, mat)->born();
    getCelluleAt(48, 55, mat)->born();

    getCelluleAt(49, 52, mat)->born();
    getCelluleAt(49, 56, mat)->born();


    getCelluleAt(50, 53, mat)->born();
    getCelluleAt(50, 54, mat)->born();
    getCelluleAt(50, 55, mat)->born();

    getCelluleAt(51, 51, mat)->born();
    getCelluleAt(51, 52, mat)->born();

    getCelluleAt(51, 56, mat)->born();
    getCelluleAt(51, 57, mat)->born();

    getCelluleAt(62, 54, mat)->born();
    getCelluleAt(62, 55, mat)->born();
    getCelluleAt(63, 54, mat)->born();
    getCelluleAt(63, 55, mat)->born();
}

void createGunGlider(Cell mat[]) {
    getCelluleAt(1, 5, mat)->born();
    getCelluleAt(2, 5, mat)->born();
    getCelluleAt(1, 6, mat)->born();
    getCelluleAt(2, 6, mat)->born();

    getCelluleAt(11, 5, mat)->born();
    getCelluleAt(11, 6, mat)->born();
    getCelluleAt(11, 7, mat)->born();
    getCelluleAt(11, 8, mat)->born();

    getCelluleAt(12, 4, mat)->born();
    getCelluleAt(12, 9, mat)->born();

    getCelluleAt(13, 3, mat)->born();
    getCelluleAt(14, 3, mat)->born();
    getCelluleAt(13, 10, mat)->born();
    getCelluleAt(14, 10, mat)->born();

    getCelluleAt(15, 7, mat)->born();

    getCelluleAt(16, 4, mat)->born();
    getCelluleAt(16, 9, mat)->born();

    getCelluleAt(17, 5, mat)->born();
    getCelluleAt(17, 6, mat)->born();
    getCelluleAt(17, 7, mat)->born();

    getCelluleAt(18, 6, mat)->born();

    getCelluleAt(21, 4, mat)->born();
    getCelluleAt(21, 5, mat)->born();
    getCelluleAt(21, 6, mat)->born();

    getCelluleAt(22, 4, mat)->born();
    getCelluleAt(22, 5, mat)->born();
    getCelluleAt(22, 6, mat)->born();

    getCelluleAt(23, 3, mat)->born();
    getCelluleAt(23, 7, mat)->born();

    getCelluleAt(25, 2, mat)->born();
    getCelluleAt(25, 3, mat)->born();

    getCelluleAt(25, 7, mat)->born();
    getCelluleAt(25, 8, mat)->born();

    getCelluleAt(35, 3, mat)->born();
    getCelluleAt(35, 4, mat)->born();
    getCelluleAt(36, 3, mat)->born();
    getCelluleAt(36, 4, mat)->born();
}

void initMatrix(Cell mat[], Cell matNext[]) {
    Cell cell = Cell();

    for(int i = 0; i < LENGHT; i++) {
        if(i == 0) {
            cell.pos.x = 0;
            cell.pos.y = 0;
        } else if(i % N == 0) {
            cell.pos.x = 0;
            cell.pos.y++;
        } else {
            cell.pos.x++;
        }

        mat[i] = cell;
        matNext[i] = cell;
    }
    giveLife(matNext);

}


int main()
{
    sf::RenderWindow window(sf::VideoMode(N*SIZE, N*SIZE), "APP");
    window.setFramerateLimit(FRAME_LIMIT);

    Cell mat[LENGHT];
    Cell matNext[LENGHT];

    sf::RectangleShape cellGraphic(sf::Vector2f(SIZE, SIZE));

    std::vector<sf::RectangleShape> matrixGraphic(LENGHT, sf::RectangleShape(cellGraphic));

    initMatrix(mat, matNext);
    int index = 0;

    // displayCells(matNext);

    for(int i = 0; i < LENGHT; i++) {
        matrixGraphic[i].setPosition(mat[i].pos.x * SIZE , mat[i].pos.y * SIZE);
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        nextStep(mat, matNext);

        for(int i = 0 ; i < LENGHT; i++) {
            mat[i] = matNext[i];
            if(mat[i].isAlive()) {
                matrixGraphic[i].setFillColor(sf::Color::White);
            } else {
                matrixGraphic[i].setFillColor(sf::Color::Black);
            }
            window.draw(matrixGraphic[i]);
        }


        window.display();
    }

    return 0;
}
