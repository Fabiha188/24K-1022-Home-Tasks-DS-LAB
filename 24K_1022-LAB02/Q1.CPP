#include <iostream>
using namespace std;

class Array {
    int* arr;
    int size;     
    int current;  

public:
    Array() {
        size = 1;
        current = 0;
        arr = new int[size];
    }

    Array(int n) {
        size = n > 0 ? n : 1;
        current = 0;
        arr = new int[size];
    }

    ~Array() {
        delete[] arr;
    }

    void push_back(int num) {
        if (current == size) {
            int oldSize = size;
            size = size * 2;
            int* dup = new int[size];

            for (int i = 0; i < current; i++) {
                dup[i] = arr[i];
            }

            delete[] arr;
            arr = dup;
        }
        arr[current] = num;
        current++;
    }

    void display() {
        for (int i = 0; i < current; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    Array a(2);
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);  
    a.push_back(40);
    a.display();      
    return 0;
}
