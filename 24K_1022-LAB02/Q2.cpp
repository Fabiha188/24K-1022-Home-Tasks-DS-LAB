#include <iostream>
using namespace std;

class Array {
    int** arr;
    int row, col;     
public:
    Array(int c, int r) {
        row = r;
        col = c;
        arr = new int*[row];
        for (int i = 0; i < row; i++) {
            arr[i] = new int[col];
            for (int j = 0; j < col; j++) {
                arr[i][j] = 0;
            }
        }
    }

    void transpose() {
        int** arr2 = new int*[col];
        for (int i = 0; i < col; i++) {
            arr2[i] = new int[row];
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                arr2[j][i] = arr[i][j];
            }
        }

        for (int i = 0; i < row; i++) {
            delete[] arr[i];
        }
        delete[] arr;

        arr = arr2;

        int temp = row;
        row = col;
        col = temp;
    }

    void resize(int newr, int newc, int value) {
        int** newArr = new int*[newr];
        for (int i = 0; i < newr; i++) {
            newArr[i] = new int[newc];
        }

        for (int i = 0; i < newr; i++) {
            for (int j = 0; j < newc; j++) {
                if (i < row && j < col) {
                    newArr[i][j] = arr[i][j];
                } else {
                    newArr[i][j] = value;
                }
            }
        }

        for (int i = 0; i < row; i++) {
            delete[] arr[i];
        }
        delete[] arr;

        arr = newArr;
        row = newr;
        col = newc;
    }

    void print() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int val = arr[i][j];
                if (i % 2 == 1 || j % 2 == 1) {
                    val += 2;
                }
                cout << val << " ";
            }
            cout << endl;
        }
    }

    void setValue(int r, int c, int val) {
        if (r >= 0 && r < row && c >= 0 && c < col) {
            arr[r][c] = val;
        }
    }

    ~Array() {
        for (int i = 0; i < row; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }
};

int main() {
    Array matrix(3, 2);


    matrix.setValue(0, 0, 5);
    matrix.setValue(1, 2, 7);

    cout << "Original matrix:\n";
    matrix.print();

    matrix.transpose();
    cout << "\nAfter transpose:\n";
    matrix.print();

    matrix.resize(4, 5, 9);
    cout << "\nAfter resize to 4x5 with fill value 9:\n";
    matrix.print();

    return 0;
}
