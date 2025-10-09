#include <iostream>
using namespace std;

#define N 5

int maze[N][N] = {
    {1, 1, 1, 0, 1},
    {0, 1, 0, 1, 1},
    {1, 1, 1, 1, 0},
    {0, 1, 0, 1, 1},
    {1, 1, 1, 0, 1}
};

void printPath(int path[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << path[i][j] << " ";
        cout << endl;
    }
    cout << "------------------\n";
}

bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

void findPaths(int x, int y, int destX, int destY, int path[N][N], const string &who) {
    if (x == destX && y == destY) {
        path[x][y] = 1;
        cout << who << " Path to (" << destX << "," << destY << "):\n";
        printPath(path);
        path[x][y] = 0;
        return;
    }

    if (isSafe(x, y) && path[x][y] == 0) {
        path[x][y] = 1;
        findPaths(x, y + 1, destX, destY, path, who);
        findPaths(x + 1, y, destX, destY, path, who);
        findPaths(x, y - 1, destX, destY, path, who);
        findPaths(x - 1, y, destX, destY, path, who);
        path[x][y] = 0;
    }
}

void findIntersections(int rabbitPath[N][N], int catPath[N][N]) {
    cout << "\nIntersection Points (Cells visited by both):\n";
    bool found = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (rabbitPath[i][j] == 1 && catPath[i][j] == 1) {
                cout << "(" << i << "," << j << ")\n";
                found = true;
            }
        }
    }
    if (!found)
        cout << "No intersection points found!\n";
}

int main() {
    int rabbitPath[N][N] = {0};
    int catPath[N][N] = {0};

    cout << "Jungle Maze (1 = Path, 0 = Blocked):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << maze[i][j] << " ";
        cout << endl;
    }

    cout << "\n Rabbit starts at (0,0),  Cat starts at (4,4), Food at (2,2)\n";

    cout << "\n--- Rabbit Paths ---\n";
    findPaths(0, 0, 2, 2, rabbitPath, "Rabbit");

    cout << "\n--- Cat Paths ---\n";
    findPaths(4, 4, 2, 2, catPath, "Cat");

    findIntersections(rabbitPath, catPath);

    return 0;
}
