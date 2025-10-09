// Q3: The warehouse grid has free paths (1) and obstacles (0). 
// Backtracking is used to find a path from top-left to bottom-right. 
// If multiple paths exist, the algorithm explores directions in a fixed order (e.g., right, down, left, up) 
// and chooses the first valid complete path it finds.

#include <iostream>
using namespace std;

#define N 4  // size of the grid


void printSolution(int sol[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}


bool isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}


bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) {
  
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }

    
    if (isSafe(maze, x, y)) {
        sol[x][y] = 1; 

  
        if (solveMazeUtil(maze, x, y + 1, sol))
            return true;

    
        if (solveMazeUtil(maze, x + 1, y, sol))
            return true;

       
        if (solveMazeUtil(maze, x, y - 1, sol))
            return true;

       
        if (solveMazeUtil(maze, x - 1, y, sol))
            return true;

       
        sol[x][y] = 0;
        return false;
    }

    return false;
}

// Main function to solve the maze using backtracking
void solveMaze(int maze[N][N]) {
    int sol[N][N] = {0}; // solution matrix initialized to 0

    if (solveMazeUtil(maze, 0, 0, sol)) {
        cout << "Path found by robot:\n";
        printSolution(sol);
    } else {
        cout << "No path exists!\n";
    }
}

int main() {
    int maze[N][N] = {
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 1},
        {1, 0, 1, 1}
    };

    solveMaze(maze);
    return 0;
}
