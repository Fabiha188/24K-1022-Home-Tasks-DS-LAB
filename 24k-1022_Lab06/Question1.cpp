#include <iostream>
#include <string>
using namespace std;

class Call {
public:
    string name;
    string number;
    string duration;

    Call() {
        name = "";
        number = "";
        duration = "";
    }

    Call(string n, string num, string d) {
        name = n;
        number = num;
        duration = d;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Number: " << number << endl;
        cout << "Duration: " << duration << endl;
    }
};

class Stack {
private:
    int topIndex;
    int limit;
    Call* array;

public:
    Stack(int s) {
        limit = s;
        topIndex = -1;
        array = new Call[limit];
    }

    ~Stack() {
        delete[] array;
    }

    bool empty() {
        return topIndex == -1;
    }

    bool isFull() {
        return topIndex == limit - 1;
    }

    void push(Call c) {
        if (isFull()) {
            cout << "Call history is full! Cannot add new calls.\n";
            return;
        }
        array[++topIndex] = c;
        cout << " New call added to history.\n";
        displayAll();
    }

    void pop() {
        if (empty()) {
            cout << " The call history is empty.\n";
            return;
        }
        cout << " Removed Call:\n";
        array[topIndex].display();
        topIndex--;
        displayAll();
    }

    void top() {
        if (empty()) {
            cout << " No recent call.\n";
            return;
        }
        cout << "\n---- Most Recent Call ----\n";
        array[topIndex].display();
        cout << "--------------------------\n";
    }

    void displayAll() {
        if (empty()) {
            cout << "\n Call history is empty.\n";
            return;
        }
        cout << "\n====== Current Call History ======\n";
        for (int i = topIndex; i >= 0; i--) {
            cout << "Call " << (i + 1) << ":\n";
            array[i].display();
            cout << "-----------------------\n";
        }
        cout << "=================================\n";
    }
};

int main() {
    int size, choice;
    cout << "Enter maximum number of call records to store: ";
    cin >> size;

    Stack history(size);

    do {
        cout << "\n========== Mobile Call History ==========\n";
        cout << "1. Add New Call\n";
        cout << "2. View Most Recent Call\n";
        cout << "3. Remove Most Recent Call\n";
        cout << "4. View All Calls\n";
        cout << "5. Check if Call History is Empty\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, num, duration;
                cin.ignore();
                cout << "Enter Caller Name: ";
                getline(cin, name);
                cout << "Enter Phone Number: ";
                getline(cin, num);
                cout << "Enter Call Duration (e.g., 5 mins): ";
                getline(cin, duration);

                Call c(name, num, duration);
                history.push(c);
                break;
            }

            case 2:
                history.top();
                history.displayAll();
                break;

            case 3:
                history.pop();
                break;

            case 4:
                history.displayAll();
                break;

            case 5:
                if (history.empty())
                    cout << "Call history is empty.\n";
                else
                    cout << " Call history has records.\n";
                break;

            case 6:
                cout << " Exiting Call History System... Goodbye!\n";
                break;

            default:
                cout << " Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
