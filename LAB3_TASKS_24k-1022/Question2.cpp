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
    if(!head){
        addHead(n,p);
        return;
    }
    node* nn = new node(n,p);
    node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=nn;
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
    void deleteHead(){
        if(!head){
            cout<<"Card Empty";
            return;
        }
        else{
            node* temp=head;
            head=head->next;
            cout << "Deleted: " << temp->name << " - $" << temp->price << endl;
            delete temp;
        }
    }
    void SearchByPosition(int pos){
        if(!head){
            cout<<"Card Empty";
            return;
        }
        if(pos==1){
            cout << "At position " << pos << ": "
                 << head->name << " - $" << head->price << endl;
                 return;
        }
        else{
            node* temp=head;
            int i=1;
            while(temp!=nullptr && i<pos){
                  temp=temp->next;
                  i++;
            }
            if(temp==nullptr){
                cout<<"Invalid Position\n";

            }
            else{
                cout << "At position " << pos << ": "
                 << temp->name << " - $" << temp->price << endl;
            }
        }

    }


};
int main() {
    shoppingCart cart;

   
    cart.addTail("Laptop", 1000);
    cart.addTail("Phone", 500);
    cart.addTail("Tablet", 300);
    cart.addTail("Headphones", 150);

    cout << "Entire Cart:" << endl;
    cart.display();

    cout << "\nSearching by Item Name (Phone):" << endl;
    cart.searchItemName("Phone");

    cout << "\nSearching by Item Name (Camera):" << endl;
    cart.searchItemName("Camera");

    cout << "\nSearching by Position (3):" << endl;
    cart.SearchByPosition(3);

    cout << "\nSearching by Position (5):" << endl;
    cart.SearchByPosition(5);

    cout << "\nDeleting first item...\n";
    cart.deleteHead();
    cart.display();

    return 0;
}
