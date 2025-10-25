//stack implementation
#include <iostream>
using namespace std;
#include <string>

class call{
    public:
    string name;
    string time;
    string number;
    call(){
        name="";
        time="";
        number="";
    }
    call(string n,string t,string nu){
        name=n;
        time=t;
        number=nu;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Number: "<<number<<endl;
        cout<<"Call Time: "<<time<<endl;
    }
    
};
class Stack{
    private:
    int top;
    int limit;
    call* array;
    public:
    Stack(int s){
        limit=s;
        top=-1;
        array=new call[limit];
    }
    ~Stack(){
        delete[] array;
    }

    bool isEmpty(){
        return top==-1;
    }
    bool isFull(){
        return top==limit-1;
    }
    void push(call c){
        if(isFull()){
            cout<<"The  Stack is Overfull\n";
            return;
        }
        array[++top]=c;
        cout<<"New Call Added To History....\n";
    }
    void pop(){
        if(isEmpty()){
            cout<<"The Call History Is Empty\n";
            return;
        }
        cout<<"Removed Call: \n";
        array[top].display();
        top--;
    }
    void peek(){
        if(isEmpty()){
            cout<<"No  Recent Call...\n";
            return;
        }
        cout<<"----Most Recent Call----\n";
        array[top].display();
        cout<<"\n------------------------\n";
    }
    void displayAll(){
        if(isEmpty()){
            cout<<"Call History Is Empty...\n";
            return;
        }
        cout<<"\n======Call History=========\n";
        for(int i=top;i>=0;i--){
            cout<<"Call "<<i+1<<": \n";
            array[i].display();
        }
        cout<<"\n=============================\n";
    }
};
int main(){
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
                string name, num, time;
                cin.ignore();
                cout << "Enter Caller Name: ";
                getline(cin, name);
                cout << "Enter Phone Number: ";
                getline(cin, num);
                cout << "Enter Call Time (e.g., 10:30 PM): ";
                getline(cin, time);

                call c(name, time, num);
                history.push(c);
                break;
            }

            case 2:
                history.peek();
                break;

            case 3:
                history.pop();
                break;

            case 4:
                history.displayAll();
                break;

            case 5:
                if (history.isEmpty())
                    cout << "Call History is Empty.\n";
                else
                    cout << " Call History has records.\n";
                break;

            case 6:
                cout << "Exiting Call History System... Goodbye!\n";
                break;

            default:
                cout <<" Invalid Choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
