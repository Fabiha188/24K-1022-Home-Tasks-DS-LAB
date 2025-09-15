#include <iostream>
using namespace std;
class node{
    public:
    int id;
    string name;
    int price;
    node* next;
    node* previous;
    node(){
        name="";
        id=0;
        price=0;
        next=nullptr;
        previous=nullptr;
    }
    node(int i,string n,int pr){
        name=n;
        id=i;
        price=pr;
        next=nullptr;
        previous=nullptr;
    }
};
class shoppingCart{
    node* head;
    node* tail;
    public:
    shoppingCart(){
        head=nullptr;
        tail=nullptr;
    }
    void insertTail(int i,string n,int pr){
        node* nn=new node(i,n,pr);
        if(!head){
            head=tail=nn;
            return;
        }
        tail->next=nn;
        nn->previous=tail;
        tail=nn;

    }
    void insertHead(int i,string n,int pr){
        node* nn=new node(i,n,pr);
        if(!head){
            head=tail=nn;
            return;
        }
        nn->next=head;
        head->previous=nn;
        head=nn;
    }
    void removeFront(){
        if(!head){
            cout<<"cart empty...";
            return;
        }
        if(head==tail){
            delete head;
            head=tail=nullptr;
            return;
        }
        node* temp=head;
        head=head->next;
        head->previous=nullptr;
        cout << "Removed: " << temp->id << " - " << temp->name << " - $" << temp->price << endl;
        delete temp;
    }
    void removeEnd(){
        if(!head){
            cout<<"cart empty...";
            return;
        }
        if(head==tail){
            delete head;
            head=tail=nullptr;
            return;
        }
        node* temp=tail;
        tail=tail->previous;
        tail->next=nullptr;
        cout << "Removed: " << temp->id << " - " << temp->name << " - $" << temp->price << endl;
        delete temp;
    }
    void searchID(int id){
        if(!head){
            cout<<"cart empty...";
            return;
        }
        bool found=0;
        node* temp=head;
        while(temp!=nullptr){
            if(temp->id==id){
                cout<<"Found ID: "<<temp->id<<"\nName: "<<temp->name<<"\nPrice: "<<temp->price<<endl;
                found=1;
                return;
            }
            temp=temp->next;
        }
        if(!found){
            cout<<id<<" not found\n";
        }

    }
    void updatePrice(int id,int newp){
        if(!head){
            cout<<"cart empty...";
            return;
        }
        bool found=0;
        node* temp=head;
        while(temp!=nullptr){
            if(temp->id==id){
                temp->price=newp;
                cout<<"Found ID: "<<temp->id<<"\nName: "<<temp->name<<"\nNew Price: "<<temp->price<<endl;
                found=1;
                return;
            }
            temp=temp->next;
        }
        if(!found){
            cout<<id<<" not found\n";
        }
    }
    void displayForward(){
        if(!head){
            cout<<"cart empty...";
            return;
        }
        node* temp=head;
        while(temp!=nullptr){
             cout << temp->id << " - " << temp->name
             << " - $" << temp->price << endl;
            temp = temp->next;
        }
    }
    void displayBackward(){
        if(!head ){
            cout<<"cart empty...";
            return;
        }
        node* temp=tail;
        while(temp!=nullptr){
             cout << temp->id << " - " << temp->name
             << " - $" << temp->price << endl;
            temp = temp->previous;
        }
    }
    int countItems(){
        if(!head ){
            cout<<"cart empty...";
            return 0;
        }
        int count=0;
        node* temp=head;
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
        return count;
    }
    void mostExpensive(){
        if(!head){
            cout<<"Cart Empty!...";
            return;
        }
        node* temp=head;
        node* max=head;
        while(temp!=nullptr){
            if(max->price<temp->price){
                max=temp;
            }
            temp=temp->next;
        }
        cout << "Most Expensive Item: " << max->id
             << " - " << max->name
             << " - $" << max->price << endl;
    }
};
int main() {
    shoppingCart cart;

    cout << "Inserting items at tail:\n";
    cart.insertTail(1, "Laptop", 1000);
    cart.insertTail(2, "Phone", 600);
    cart.insertTail(3, "Tablet", 400);
    cart.displayForward();

    cout << "\nInserting item at head:\n";
    cart.insertHead(0, "Smartwatch", 250);
    cart.displayForward();

    cout << "\nDisplay cart backward:\n";
    cart.displayBackward();

    cout << "\nSearch for ID 2:\n";
    cart.searchID(2);

    cout << "\nUpdate price for ID 3:\n";
    cart.updatePrice(3, 450);
    cart.displayForward();

    cout << "\nCount items:\n";
    cout << "Total items: " << cart.countItems() << endl;

    cout << "\nMost expensive item:\n";
    cart.mostExpensive();

    cout << "\nRemove front:\n";
    cart.removeFront();
    cart.displayForward();

    cout << "\nRemove end:\n";
    cart.removeEnd();
    cart.displayForward();

    return 0;
}
