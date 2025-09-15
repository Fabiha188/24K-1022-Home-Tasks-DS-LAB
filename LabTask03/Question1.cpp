#include <iostream>
using namespace std;
class node{
    public:
    string name;
    int price;
    node* next;
    node(){
        name="";
        price=0;
        next=nullptr;
    }
    node(string n,int p){
        name=n;
        price=p;
        next=nullptr;
    }
};
class shoppingCart{
    node* head;
    public:
    shoppingCart(){
        head=nullptr;
    }
    void addHead(string n,int p){
        node* nn=new node(n,p);
        nn->next=head;
        head=nn;
    }
    void addTail(string n,int p){
        node* nn =new node(n,p);
        if(!head){
            addHead(n,p);
            delete nn;
            return;
        }
        else{
            node* temp=head;
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next=nn;
        }
    }
    void insertAfterValue(string t,string n,int p){
        if(!head){
            return;
        }
        bool found=0;
        node* temp=head;
        node* nn=new node(n,p);
        while(temp!=nullptr){
            if(temp->name==t){
                nn->next=temp->next;
                temp->next=nn;
                found=1;
                return;
            }
            temp=temp->next;
        }
        if(!found){
            cout<<"Item "<<t<<" not found!...\n";
        }
    }
    void searchItemName(string n){
        if(!head){
            cout<<"Card Empty";
            return;
        }
        bool found=0;
        node* temp=head;
        while(temp!=nullptr){
            if(temp->name==n){
                cout<<"Found: Item Name: "<<temp->name<<" \nprice: "<<temp->price<<endl;
                found++;
            }
            temp=temp->next;
        }
        if(!found){
            cout<<"Item "<<n<<" not found!...\n";
        }
    }
    void display(){
        if(!head){
            cout<<"Card Empty";
            return;
        }
        node* temp=head;
        cout << "\nShopping Cart Items:\n";
        while(temp!=nullptr){
             cout << temp->name << " - $" << temp->price << endl;
            temp = temp->next;
        }
    }


};
int main() {
    shoppingCart cart;

    cout << "Adding initial items...\n";
    cart.addTail("Laptop", 1000);
    cart.addTail("Phone", 700);
    cart.addTail("Tablet", 400);
    cart.addTail("Headphones", 150);
    cart.display();

    cout << "\nAdding Smartwatch at front...\n";
    cart.addHead("Smartwatch", 200);
    cart.display();

    cout << "\nAdding Keyboard at end...\n";
    cart.addTail("Keyboard", 80);
    cart.display();

    cout << "\nInserting Monitor after Phone...\n";
    cart.insertAfterValue("Phone", "Monitor", 300);
    cart.display();

    cout << "\nSearching for Tablet...\n";
    cart.searchItemName("Tablet");

    cout << "\nFinal Cart:\n";
    cart.display();

    return 0;
}

