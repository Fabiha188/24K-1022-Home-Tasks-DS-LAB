#include <iostream>
#include <string>
using namespace std;

class PatronQueue {
private:
    int front, rear, capacity;
    string* queue;

public:
    PatronQueue(int size) {
        capacity = size;
        queue = new string[capacity];
        front = rear = -1;
    }

    ~PatronQueue() {
        delete[] queue;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    // Add patron to queue
    void enqueue(string name) {
        if (isFull()) {
            cout << "Queue is full! Please wait...\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        queue[rear] = name;
        cout << name << " has joined the queue.\n";
    }

    // Remove patron after service
    void dequeue() {
        if (isEmpty()) {
            cout << "No patrons waiting (Underflow).\n";
            return;
        }
        cout << queue[front] << " has completed their transaction.\n";

        if (front == rear) {
           
            front = rear = -1;
        } else {
            front++;
        }
    }

   
    void display() {
        if (isEmpty()) {
            cout << "No patrons currently in queue.\n";
            return;
        }
        cout << "\n=== Current Queue of Patrons ===\n";
        for (int i = front; i <= rear; i++) {
            cout << i - front + 1 << ". " << queue[i] << endl;
        }
        cout << "================================\n";
    }
};

int main() {
    PatronQueue libraryQueue(5); 
    int choice;
    string name;

    cout << "===== Library Book Transaction System =====\n";

    do {
        cout << "\n1. Patron Arrives (Enqueue)";
        cout << "\n2. Patron Served (Dequeue)";
        cout << "\n3. Display Queue";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Patron Name: ";
            cin.ignore();
            getline(cin,name);
            libraryQueue.enqueue(name);
            break;
        case 2:
            libraryQueue.dequeue();
            break;
        case 3:
            libraryQueue.display();
            break;
        case 4:
            cout << "Exiting System...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
