#include <iostream>
#include <string>
using namespace std;

class History {
public:
    string url;
    History* next;

    History(string u = "") {
        url = u;
        next = nullptr;
    }
};


class HistoryList {
public:
    History* head;
    HistoryList() {
        head = nullptr;
    }

    void addToFront(string url) {
        History* temp = new History(url);
        temp->next = head;
        head = temp;
    }

    void removeFront() {
        if (!head) return;
        History* temp = head;
        head = head->next;
        delete temp;
    }

    void display() {
        cout << "\n--- Browsing History (Most Recent First) ---\n";
        History* temp = head;
        while (temp) {
            cout << temp->url << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};


class Stack {
private:
    History* top;
public:
    Stack() {
        top = nullptr;
    }

    void push(string url) {
        History* temp = new History(url);
        temp->next = top;
        top = temp;
    }

    string pop() {
        if (!top) {
            cout << "No pages to go back to.\n";
            return "";
        }
        string page = top->url;
        History* temp = top;
        top = top->next;
        delete temp;
        return page;
    }

    void displayStack() {
        cout << "\n--- Stack (Back History) ---\n";
        History* temp = top;
        while (temp) {
            cout << temp->url << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    HistoryList history;
    Stack backStack;

   
    string sites[] = {"Google", "Facebook", "Twitter", "LinkedIn", "Instagram"};

    cout << "User visits websites...\n";
    for (int i = 0; i < 5; i++) {
        history.addToFront(sites[i]);  
        backStack.push(sites[i]);      
        cout << "Visited: " << sites[i] << endl;
    }

    history.display();
    backStack.displayStack();


    cout << "\nUser clicks BACK twice...\n";
    backStack.pop();
    history.removeFront();  

    backStack.pop();
    history.removeFront();  

    history.display();

    cout << "\nUser is now on: Facebook\n";

    return 0;
}
