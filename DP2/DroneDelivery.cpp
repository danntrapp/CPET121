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

constexpr int BOARD_SIZE   = 11;
constexpr int DRONE_COUNT  = 8;
constexpr int MAX_DIST     = 999999999;
constexpr int WAREHOUSE_X  = 5;
constexpr int WAREHOUSE_Y  = 5;

// ============================================================
// Name: getDistanceSq()
// Input: Two (x, y) positions
// Output: int - squared Euclidean distance between them
// Purpose: Returns the squared distance to avoid floating-point
//          math while still allowing relative comparisons.
// ============================================================
int getDistanceSq(int ax, int ay, int bx, int by)
{
    int deltaX = std::abs(ax - bx);
    int deltaY = std::abs(ay - by);
    return (deltaX * deltaX) + (deltaY * deltaY);
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
            std::cout << board[i][j] << "  ";
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
bool isValid(int x, int y)
{
    bool outOfBounds = (x >= BOARD_SIZE || x < 0 ||
                        y >= BOARD_SIZE || y < 0);
    bool isWarehouse = (x == WAREHOUSE_X && y == WAREHOUSE_Y);

    if (outOfBounds || isWarehouse)
    {
        std::cout << "Invalid coordinate\n";
        return false;
    }
    return true;
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
    int minDist  = MAX_DIST;
    int minIndex = 0;

    for (int i = 0; i < DRONE_COUNT; i++)
    {
        int distSq = getDistanceSq(droneXs[i], droneYs[i], targetX, targetY) +
                     getDistanceSq(droneXs[i], droneYs[i], WAREHOUSE_X, WAREHOUSE_Y);

        if (distSq < minDist)
        {
            minDist  = distSq;
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
    int oldX      = droneXs[droneIndex];
    int oldY      = droneYs[droneIndex];
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

    int droneXs[DRONE_COUNT] = {2, 2, 2, 5, 5, 8, 8, 8};
    int droneYs[DRONE_COUNT] = {2, 5, 8, 2, 8, 2, 5, 8};

    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            board[i][j] = '*';

    board[WAREHOUSE_X][WAREHOUSE_Y] = 'W';

    for (int i = 0; i < DRONE_COUNT; i++)
        board[droneXs[i]][droneYs[i]] = '0' + static_cast<char>(i);

    std::cout << "Starting Board\n\n";
    printBoard(board);
    std::cout << "\n";

    char continueFlag = 'Y';
    while (continueFlag == 'Y')
    {
        int inputX, inputY;
        std::cout << "X value: ";
        std::cin >> inputX;
        std::cout << "Y value: ";
        std::cin >> inputY;

        if (isValid(inputX, inputY))
        {
            int closestIdx = indexOfClosest(inputX, inputY, droneXs, droneYs);
            std::cout << "Drone #" << closestIdx << " is closest\n";
            moveDrone(inputX, inputY, closestIdx, board, droneXs, droneYs);
            std::cout << "New Board\n\n";
            printBoard(board);
        }

        std::cout << "Type 'Y' to continue: ";
        std::cin >> continueFlag;
        std::cout << "\n";
    }

    return 0;
}