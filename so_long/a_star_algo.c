#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define ROWS 5
#define COLS 5

typedef struct {
    int row, col;
} Point;

typedef struct {
    Point parent;
    int f, g, h;
} Node;

// Function to check if a point is within the bounds of the grid
bool isValid(int row, int col) {
    return (row >= 0) && (row < ROWS) && (col >= 0) && (col < COLS);
}

// Function to check if a cell is blocked or not
bool isBlocked(int grid[ROWS][COLS], int row, int col) {
    return grid[row][col] == 1;  // Assuming 1 represents a blocked cell
}

// Function to calculate the Manhattan distance heuristic
int calculateHeuristic(Point current, Point goal) {
    return abs(current.row - goal.row) + abs(current.col - goal.col);
}

// A* algorithm implementation
void aStar(int grid[ROWS][COLS], Point start, Point goal) {
    Node openSet[ROWS * COLS];
    Node closedSet[ROWS][COLS];

    // Initialize open and closed sets
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            closedSet[i][j].f = closedSet[i][j].g = closedSet[i][j].h = INT_MAX;
        }
    }

    int openSetSize = 0;
    openSet[0].parent = start;
    openSet[0].f = openSet[0].g = openSet[0].h = 0;

    while (openSetSize > 0) {
        // Find node with the lowest f in open set
        int currentIdx = 0;
        for (int i = 1; i < openSetSize; i++) {
            if (openSet[i].f < openSet[currentIdx].f) {
                currentIdx = i;
            }
        }

        Node current = openSet[currentIdx];

        // Goal reached, reconstruct path
        if (current.parent.row == goal.row && current.parent.col == goal.col) {
            printf("Path Found!\n");
            Point path[ROWS * COLS];
            int pathLength = 0;

            while (!(current.parent.row == start.row && current.parent.col == start.col)) {
                path[pathLength++] = current.parent;
                current = closedSet[current.parent.row][current.parent.col];
            }

            printf("Path: ");
            for (int i = pathLength - 1; i >= 0; i--) {
                printf("(%d, %d) ", path[i].row, path[i].col);
            }
            printf("(%d, %d)\n", goal.row, goal.col);
            return;
        }

        // Remove current node from open set
        for (int i = currentIdx; i < openSetSize - 1; i++) {
            openSet[i] = openSet[i + 1];
        }
        openSetSize--;

        // Add current node to closed set
        closedSet[current.parent.row][current.parent.col] = current;

        // Explore neighbors
        Point neighbors[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; i++) {
            Point neighbor = {current.parent.row + neighbors[i].row, current.parent.col + neighbors[i].col};

            if (isValid(neighbor.row, neighbor.col) && !isBlocked(grid, neighbor.row, neighbor.col)) {
                int tentativeG = current.g + 1;  // Assuming cost of movement is 1

                // Check if the neighbor is already in the closed set with a lower cost
                if (tentativeG < closedSet[neighbor.row][neighbor.col].g) {
                    int h = calculateHeuristic(neighbor, goal);
                    Node neighborNode = {current.parent, tentativeG + h, tentativeG, h};

                    // Check if the neighbor is not in the open set or has a lower cost
                    bool isNewNode = true;
                    for (int j = 0; j < openSetSize; j++) {
                        if (openSet[j].parent.row == neighborNode.parent.row &&
                            openSet[j].parent.col == neighborNode.parent.col) {
                            isNewNode = false;
                            if (neighborNode.g < openSet[j].g) {
                                openSet[j] = neighborNode;
                            }
                            break;
                        }
                    }

                    if (isNewNode) {
                        openSet[openSetSize++] = neighborNode;
                    }
                }
            }
        }
    }

    printf("Path not found.\n");
}

int main() {
    int grid[ROWS][COLS] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };

    Point start = {0, 0};
    Point goal = {4, 4};

    aStar(grid, start, goal);

    return 0;
}
