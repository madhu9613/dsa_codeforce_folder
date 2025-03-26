#include <iostream>
using namespace std;

#define N 4

// A utility function to check if x, y is valid index for N*N maze
bool isSafe(int maze[N][N], int x, int y, int sol[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && sol[x][y] == 0);
}

// A recursive utility function to solve the maze problem
void solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N], string path) {
    // If x, y is the bottom-right cell, print the path
    if (x == N - 1 && y == N - 1) {
        cout << path << endl;
        return;
    }

    // Check if maze[x][y] is a valid move
    if (isSafe(maze, x, y, sol)) {
        // Mark x, y as part of the solution path
        sol[x][y] = 1;

        // Move Down (D)
        solveMazeUtil(maze, x + 1, y, sol, path + 'D');

        // Move Left (L)
        solveMazeUtil(maze, x, y - 1, sol, path + 'L');

        // Move Right (R)
        solveMazeUtil(maze, x, y + 1, sol, path + 'R');

        // Move Up (U)
        solveMazeUtil(maze, x - 1, y, sol, path + 'U');

        // Backtrack: unmark x, y as part of the solution path
        sol[x][y] = 0;
    }
}

// Function to solve the Maze problem and print all paths in DLRU order
void solveMaze(int maze[N][N]) {
    int sol[N][N] = { { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 } };

    solveMazeUtil(maze, 0, 0, sol, "");
}

int main() {
    int maze[N][N] = { { 1, 0, 0, 0 },
                       { 1, 1, 0, 1 },
                       { 1, 1, 1, 0 },
                       { 1, 1, 1, 1 } };

    solveMaze(maze);
    return 0;
}
