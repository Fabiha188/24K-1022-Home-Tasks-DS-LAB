#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int id;
    string name;
    string ride;
    Node* next;
    Node(int i,string n,string r) {
        id=i;
        name=n;
        ride=r;
        next=NULL;
    }
};

class CircularList {
    Node* last;
public:
    CircularList() {
        last=NULL;
    }
    void issueEnd(int i,string n,string r) {
        Node* t=new Node(i,n,r);
        if(!last) {
            last=t;
            last->next=last;
        } else {
            t->next=last->next;
            last->next=t;
            last=t;
        }
    }
    void issueFront(int i,string n,string r) {
        Node* t=new Node(i,n,r);
        if(!last) {
            last=t;
            last->next=last;
        } else {
            t->next=last->next;
            last->next=t;
        }
    }
    void cancelById(int i) {
        if(!last) return;
        Node* cur=last->next;
        Node* prev=last;
        do {
            if(cur->id==i) {
                if(cur==last && cur==last->next) {
                    delete cur;
                    last=NULL;
                    return;
                }
                if(cur==last) last=prev;
                prev->next=cur->next;
                delete cur;
                return;
            }
            prev=cur;
            cur=cur->next;
        } while(cur!=last->next);
    }
    void cancelFirst() {
        if(!last) return;
        Node* f=last->next;
        if(f==last) {
            delete f;
            last=NULL;
        } else {
            last->next=f->next;
            delete f;
        }
    }
    void searchId(int i) {
        if(!last) return;
        Node* cur=last->next;
        do {
            if(cur->id==i) {
                cout<<cur->id<<" "<<cur->name<<" "<<cur->ride<<endl;
                return;
            }
            cur=cur->next;
        } while(cur!=last->next);
    }
    void display() {
        if(!last) return;
        Node* cur=last->next;
        do {
            cout<<cur->id<<" "<<cur->name<<" "<<cur->ride<<endl;
            cur=cur->next;
        } while(cur!=last->next);
    }
    void countTickets() {
        if(!last) {
            cout<<0<<endl;
            return;
        }
        int c=0;
        Node* cur=last->next;
        do {
            c++;
            cur=cur->next;
        } while(cur!=last->next);
        cout<<c<<endl;
    }
    void nextAfter(int i) {
        if(!last) return;
        Node* cur=last->next;
        do {
            if(cur->id==i) {
                cout<<cur->next->id<<" "<<cur->next->name<<" "<<cur->next->ride<<endl;
                return;
            }
            cur=cur->next;
        } while(cur!=last->next);
    }
};

int main() {
    CircularList c;

    cout<<"Issuing tickets..."<<endl;
    c.issueEnd(1,"Ali","RollerCoaster");
    c.issueEnd(2,"Sara","FerrisWheel");
    c.issueFront(3,"VIP_Ahmed","BumperCars");

    cout<<"\nAll tickets:"<<endl;
    c.display();

    cout<<"\nSearching ticket with ID 2:"<<endl;
    c.searchId(2);

    cout<<"\nCounting total tickets:"<<endl;
    c.countTickets();

    cout<<"\nNext ticket after ID 1:"<<endl;
    c.nextAfter(1);

    cout<<"\nCancel ticket with ID 2"<<endl;
    c.cancelById(2);

    cout<<"\nCancel first ticket"<<endl;
    c.cancelFirst();

    cout<<"\nAll tickets after cancellations:"<<endl;
    c.display();
}
