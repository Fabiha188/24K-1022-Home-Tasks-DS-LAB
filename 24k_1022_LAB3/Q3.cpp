using namespace std;
#include <iostream>
class node{
    public:
    int data;
    node* next;
    node* previous;
    node(){
        data=0;
        next=nullptr;
        previous=nullptr;
    }
    node(int v){
        data=v;
        next=nullptr;
        previous=nullptr;
    }
};
class DoublyLinkedList{
    node* head;
    node* tail;
    public:
    DoublyLinkedList(){
        head=nullptr;
        tail=nullptr;
    }
    void insertAtEnd(int v){
        node* nn=new node(v);
        if(head==nullptr){
            head=tail=nn;
        }
        else{
            tail->next=nn;
            nn->previous=tail;
            tail=nn;
        }
    }
    void RemoveAtFront(){
        if(head==nullptr){
            cout<<"No Element Exists\n";
            return;
        }
        node* temp=head;
        head=head->next;
        if(head!=nullptr){
            head->previous=nullptr;
        }
        else{
            tail=nullptr;
        }
        delete temp;
    }
    void display(){
        node* temp=head;
        if(head==nullptr){
            cout<<"No Element Exists\n";
            return;
        }
        else{
            while(temp!=nullptr){
                cout<<temp->data<<endl;
                temp=temp->next;

            }
        }
    }
    void searchByValue(int v){
        node* temp=head;
        int p=0;
        bool check=0;
        while(temp!=nullptr){
            if(temp->data==v){
                cout<<"At Index "<<p<<" Compartment "<<v<<" is present\n";
                check=1;
                return;

            }
            temp=temp->next;
            p++;
        }
        if(!check){
            cout<<v<<": no compartment present\n";
        }
    }

};
int main(){
    DoublyLinkedList train;
    
    train.insertAtEnd(201);
    train.insertAtEnd(202);
    train.insertAtEnd(202);
    cout<<"Initial Linked List\n";
    train.display();
    train.RemoveAtFront();
    cout<<"After Deleting Front\n";
    train.display();
    cout<<"Searching By Compartment Number: \n";
    train.searchByValue(202);
    train.searchByValue(301);

    
}
