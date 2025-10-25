#include <iostream>
using namespace std;

class Order{
    public:
    int ID;
    int quantity;
    string itemName;
    Order* next;

    Order(int i,string n,int q){
        ID=i;
        quantity=q;
        itemName=n;
        next=nullptr;
    }
    void display(){
        cout<<"Order ID: "<<ID<<endl;
        cout<<"Item Name: "<<itemName<<endl;
        cout<<"Quantity: "<<quantity<<endl;

    }
};

class orderQueue{
    private:
    Order* front;
    Order* rear;

    public:
    orderQueue(){
        front=rear=nullptr;
    }
    bool isEmpty() {
        return front == nullptr;
    }
    void enqueue(int id, string item, int qty) {
        Order* newOrder = new Order(id, item, qty);
        if (rear == nullptr) {
            front = rear = newOrder;
            return;
        }
        rear->next = newOrder;
        rear = newOrder;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << " No pending orders (Underflow)" << endl;
            return;
        }

        Order* temp = front;
        cout << "Processed Order: " << front->ID << " (" << front->itemName << ")" << endl;

        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete temp;
    }
    void displayAll() {
        if (isEmpty()) {
            cout << "No pending orders." << endl;
            return;
        }

        cout << "\n Current Orders:\n";
        Order* temp = front;
        while (temp != nullptr) {
            temp->display();
            temp=temp->next;
        }
        cout << "-----------------------------\n";
    }
};
int main() {
    orderQueue restaurant;

  
    restaurant.enqueue(1, "Burger", 2);
    restaurant.enqueue(2, "Pizza", 1);
    restaurant.enqueue(3, "Pasta", 3);

    restaurant.displayAll();

    
    restaurant.dequeue();
    restaurant.dequeue();

    restaurant.displayAll();

    
    restaurant.enqueue(4, "Sandwich", 2);

    restaurant.displayAll();

    return 0;
}
