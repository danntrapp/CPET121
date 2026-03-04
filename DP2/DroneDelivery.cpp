//
// Created by danie on 3/3/2026.
//
#include <cmath>
#include <iostream>
#include <cstring>

struct Coordinate {
    int x;
    int y;
};

using namespace std;
char board[11][11];
Coordinate drones[8] = {{2, 2}, {2, 5}, {2,8}, {5,2}, {5,8}, {8,2}, {8, 5}, {8, 8}};

constexpr int BOARD_SIZE = 11;
constexpr Coordinate WAREHOUSE = {5, 5};

int getDistanceSq(Coordinate a, Coordinate b) {
    int delta_x = abs(a.x - b.x);
    int delta_y = abs(a.y - b.y);
    return delta_x * delta_x + delta_y * delta_y;
}
void moveDrone(Coordinate newPosition, int droneIndex) {
    Coordinate coord = drones[droneIndex];
    char c = board[coord.x][coord.y];
    board[coord.x][coord.y] = '*';
    board[newPosition.x][newPosition.y] = c;
    drones[droneIndex] = newPosition;
}
int indexOfClosest(Coordinate c) {
    int minDist = 999999999;
    int index = 0;
    for (int i = 0; i < 8; i++) {
        int distSq = getDistanceSq(drones[i], c) + getDistanceSq(drones[i], WAREHOUSE);
        bool closer = distSq < minDist;
        minDist = closer ? distSq : minDist;
        index = closer ? i : index;
    }
    return index;
}
void printBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            std::printf("%c  ", board[i][j]);
        }
        std::printf("\n");
    }
}
bool isValid(Coordinate c) {
    if (c.x >= BOARD_SIZE || c.x < 0 || c.y >= BOARD_SIZE || c.y < 0 || (c.x == WAREHOUSE.x && c.y == WAREHOUSE.y)) {
        printf("Invalid coordinate\r\n");
        return false;
    }
    return true;
}
int main(void) {
    memset(board, '*', BOARD_SIZE * BOARD_SIZE);
    board[WAREHOUSE.x][WAREHOUSE.y] = 'W';
    for (int i = 0; i < 8; i++) {
        Coordinate c = drones[i];
        board[c.x][c.y] = '0' + static_cast<char>(i);
    }
    printf("Starting Board \n\n");
    printBoard();
    printf("\r\n");
    char flag = 'Y';
    while ( flag == 'Y') {
        Coordinate userInput;
        printf("X value: ");
        cin >> userInput.x;
        printf("Y value: ");
        cin >> userInput.y;
        if (isValid(userInput)) {
            printf("Drone #%d is closest\r\n", indexOfClosest(userInput));
            moveDrone(userInput, indexOfClosest(userInput));
            printf("New Board \r\n");
            printBoard();
        }
        printf("Type 'Y' to Continue: ");
        cin >> flag;
    }
    return 0;
}