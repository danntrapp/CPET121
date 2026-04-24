// ============================================================
// Title: drone_board.cpp
// Course: Computational Problem Solving I (CPET-121)
// Developer: Dan Trapp
// Date: 3/3/2026
// Description: Simulates a drone delivery system on an 11x11
//              grid. Finds the closest drone to a user-supplied
//              coordinate and moves it to that position.
// ============================================================

#include <cmath>
#include <iostream>
#include <iomanip>

const int BOARD_SIZE = 11;
const int DRONE_COUNT = 8;
const int MAX_DIST = 999999999;
const int WAREHOUSE_X = 5;
const int WAREHOUSE_Y = 5;

int droneXs[DRONE_COUNT] = {2, 2, 2, 5, 5, 8, 8, 8};
int droneYs[DRONE_COUNT] = {2, 5, 8, 2, 8, 2, 5, 8};
// ============================================================
// Name: getDist()
// Input: Two (x, y) positions
// Output: int - squared Euclidean distance between them
// Purpose: Returns the squared distance to avoid floating-point
//          math while still allowing relative comparisons.
// ============================================================
double getDist(int ax, int ay, int bx, int by)
{
    double deltaX = std::abs(bx - ax);
    double deltaY = std::abs(by - ay);
    return std::sqrt((deltaX * deltaX) + (deltaY * deltaY));
}

// ============================================================
// Name: printBoard()
// Input: board - 2D char array representing the grid
// Output: None (prints to console)
// Purpose: Displays the current state of the board.
// ============================================================
void printBoard(char board[][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            std::cout << " " << board[i][j];
        }
        std::cout << "\n";
    }
}

// ============================================================
// Name: isValid()
// Input: x, y - coordinate to validate
// Output: bool - true if coordinate is in-bounds and not the
//         warehouse position
// Purpose: Validates user input before any board operations.
// ============================================================
char isValid(int x, int y)
{
    bool outOfBounds = (x >= BOARD_SIZE || x < 0 ||
                        y >= BOARD_SIZE || y < 0);
    bool isWarehouse = (x == WAREHOUSE_X && y == WAREHOUSE_Y);
    bool onDrone = false;

    for(int i = 0; i < DRONE_COUNT; i++){
        if(x == droneXs[i] && y == droneYs[i]) {
            onDrone = true;
        }
    }

    if (outOfBounds)
    {
        return 'o';
    } else if(isWarehouse) {
        return 'w';
    } else if(onDrone) {
        return 'd';
    } else {
        return 'v';
    }
    
}

// ============================================================
// Name: indexOfClosest()
// Input: targetX, targetY  - destination coordinate
//        droneXs, droneYs  - arrays of current drone positions
// Output: int - index of the drone with the lowest combined
//         distance to target and back to the warehouse
// Purpose: Selects the most efficient drone for a delivery.
// ============================================================
int indexOfClosest(int targetX, int targetY,
                   int droneXs[], int droneYs[])
{
    int minDist = MAX_DIST;
    int minIndex = 0;

    for (int i = 0; i < DRONE_COUNT; i++)
    {
        double dist = getDist(droneXs[i], droneYs[i], WAREHOUSE_X, WAREHOUSE_Y);
        dist += getDist(WAREHOUSE_X, WAREHOUSE_Y, targetX, targetY);
        dist += getDist(targetX, targetY, droneXs[i], droneYs[i]);

        if (dist < minDist)
        {
            minDist = dist;
            minIndex = i;
        }
    }
    return minIndex;
}

// ============================================================
// Name: moveDrone()
// Input: newX, newY   - destination coordinate
//        droneIndex   - index of drone to move
//        board        - 2D char array representing the grid
//        droneXs, droneYs - arrays of current drone positions
// Output: None (modifies board and drone arrays in place)
// Purpose: Updates the board and drone position arrays to
//          reflect the drone's move to a new coordinate.
// ============================================================
void moveDrone(int newX, int newY, int droneIndex,
               char board[][BOARD_SIZE],
               int droneXs[], int droneYs[])
{
    int oldX = droneXs[droneIndex];
    int oldY = droneYs[droneIndex];
    char droneChar = board[oldX][oldY];

    board[oldX][oldY] = '*';
    board[newX][newY] = droneChar;
    droneXs[droneIndex] = newX;
    droneYs[droneIndex] = newY;
}

// ============================================================
// Name: main()
// Input: None
// Output: int - returns 0 on successful execution
// Purpose: Entry point. Initializes the board and drones,
//          then loops to accept delivery coordinates from the
//          user until they choose to stop.
// ============================================================
int main()
{
    char board[BOARD_SIZE][BOARD_SIZE];

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = '*';
        }
    }

    board[WAREHOUSE_X][WAREHOUSE_Y] = 'W';

    for (int i = 0; i < DRONE_COUNT; i++)
    {
        board[droneXs[i]][droneYs[i]] = '1' + static_cast<char>(i);
    }
    int inputX, inputY;
    std::cin >> inputX;
    std::cin >> inputY;
    board[inputX][inputY] = 'P';
    printBoard(board);
    std::cout << "\n";
    char v = isValid(inputX, inputY);

        switch(v) {
            case('w'):
            case('o'):
                std::cout << "Sorry, illegal delivery location\n";
                break;
            case('d'):
                int closestIdx = indexOfClosest(inputX, inputY, droneXs, droneYs);
                double dist = getDist(droneXs[closestIdx], droneYs[closestIdx], WAREHOUSE_X, WAREHOUSE_Y);
                dist += getDist(WAREHOUSE_X, WAREHOUSE_Y, inputX, inputY);
                dist += getDist(inputX, inputY, droneXs[closestIdx], droneYs[closestIdx]);
                std::cout << "Drone " << closestIdx + 1 << " will make the delivery\n";
                moveDrone(inputX, inputY, closestIdx, board, droneXs, droneYs);
                std::cout << std::fixed << std::setprecision(2);
                std::cout << "Thank you for using our Drone delivery service\n";
            case('v'):
                std::cout << "This drone traveled a distance of  " << dist << " blocks\n";
                break;
        }
        if(v != 'w' && v!= 'o') {
            std::cout << "Thank you for using our Drone delivery service\n";
        }

    return 0;
}