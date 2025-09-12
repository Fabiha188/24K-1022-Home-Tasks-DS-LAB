using namespace std;
#include <iostream>
#include <string>
class node{
    public:
    string name;
    node* next;
    
    node(){
        name="";
        next=nullptr;
    }
    node(string n){
        name=n;
        next=nullptr;
    }
    string getBook(){
        return name;
    }
    
};
class linkedList{
      node* head;
      public:
      linkedList() { head = nullptr; } 
      void insertAtHead(string v){
        node* nn=new node(v);
        nn->next=head;
        head=nn;
      }
      void insertAtEnd(string v){
        node* nn=new node(v);
        if(head==nullptr){
            head=nn;
            return;
        }
        node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
            temp->next=nn;
           
      }
      void display(){
          node* temp=head;
          while(temp!=nullptr){
           cout<<temp->name<<endl;

           temp=temp->next;
          }
      }
      void insertAtPosition(string v,int p){

        node* nn=new node(v);
        if (p == 0 || head == nullptr) {
            nn->next = head;
            head = nn;
            return;
        }
        node* current=head;
        node* pre=nullptr;
        
        for(int i=0;i<p;i++){
            if (current == nullptr) {
        cout << "Position " << p << " is out of range!\n";
        return; 
    }
            pre=current;
            current=current->next;
        }
        pre->next=nn;
        nn->next=current;
      }
      void searchByValue(string v){
        int p=0;
        bool check=0;
        node* temp=head;
        while(temp!=nullptr){
            if(temp->name==v){
                cout<<v<<" is present at index "<<p<<endl;
                check=1;
                return;
            }
            else{
                temp=temp->next;
                p++;
            }
        }
        if(check==0){
                cout<<v<<" doesnot exist int the linked list\n";
            }

      }
      void insertAfterValue(string v,string nv){
        int p=0;
        node* temp=head;
        while(temp!=nullptr){
            if(temp->name==v){
              node* nn=new node(nv);
              nn->next=temp->next;
              temp->next=nn;
              return;
            }
            else{
                temp=temp->next;  
            }
        }
        cout << v << " was not found in the list!\n";
      }
      void deleteAtFront(){
        if(head==nullptr){
            cout<<"no element present in linked list\n";
            return;
        }
        node* temp=head;
        head=head->next;
        delete temp;
      }
      void SearchByPosition(int p){
        node* temp=head;
        bool check=0;
        int index=0;
        if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }
        while(temp!=nullptr){
            if(index==p){
                 cout << "At index " << p << " : " << temp->name << endl;
            return;
            }
            temp = temp->next;
        index++;
        }
          cout << "Index " << p << " is out of range!\n";}
        
        
    
};
int main(){
    linkedList library;
    library.insertAtEnd("Jannat K Patty");
    library.insertAtEnd("Khizr e Rah");
    library.insertAtEnd("Siyaah");
    cout<<"Initial LinkedList...\n";
    library.display();
    library.deleteAtFront();
    cout<<"Deletion The Head Of LinkedList...\n";
    library.display();
    cout<<"\nSearching Book By Title: ";
    library.searchByValue("Siyaah");
    cout<<"\nSearching Book By Position: ";
    library.SearchByPosition(2);


    

}
