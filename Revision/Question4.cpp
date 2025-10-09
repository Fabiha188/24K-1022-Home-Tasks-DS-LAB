// Q4: A person is trapped in a burning building represented by a maze.
// 1 = safe cell, 0 = fire/blocked cell.
// Backtracking is used to find a safe escape path from top-left to bottom-right.
// (a) The algorithm recursively explores all possible safe moves (right, down, left, up).
// (b) If no safe route exists, backtracking unmarks the cell and returns false — handled by line: sol[x][y] = 0.

#include <iostream>
using namespace std;

#define N 4  // Maze size (4x4)


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


bool escapeBuilding(int maze[N][N], int x, int y, int sol[N][N]) {
   
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }

    
    if (isSafe(maze, x, y)) {
        sol[x][y] = 1; 

       
        if (escapeBuilding(maze, x, y + 1, sol))
            return true;

        
        if (escapeBuilding(maze, x + 1, y, sol))
            return true;

    
        if (escapeBuilding(maze, x, y - 1, sol))
            return true;

  
        if (escapeBuilding(maze, x - 1, y, sol))
            return true;

        sol[x][y] = 0; 
        return false;
    }

    return false;
}


void solveEscape(int maze[N][N]) {
    int sol[N][N] = {0}; 

    if (escapeBuilding(maze, 0, 0, sol)) {
        cout << "Safe escape path found:\n";
        printSolution(sol);
    } else {
        cout << "No safe escape route exists!\n";
    }
}

int main() {
    int maze[N][N] = {
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {1, 1, 0, 1},
        {0, 1, 1, 1}
    };

    solveEscape(maze);
    return 0;
}
