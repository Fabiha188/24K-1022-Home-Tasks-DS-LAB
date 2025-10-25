#include <iostream>
#include <string>
#include <cmath>  // for mathematical operations if needed
using namespace std;

class Stack{
    private:
    int size;
    int top;
    double* arr;
    public:
    Stack(int s){
        size=s;
        top=-1;
        arr=new double[size];
    }
    ~Stack(){
        delete[] arr;
    }
    bool IsEmpty(){
        return top==-1;
    }
    bool isFull(){
        return top==size-1;
    }
    void push(double v){
        if(isFull()){
             cout << "Stack overflow! Cannot push.\n";
            return;
        }
        arr[++top]=v;
    }
    double pop(){
        if(IsEmpty()){
            cout << "Stack underflow! Expression invalid.\n";
            return 0;
        }
        return arr[top--];
    }
    double topp(){
        if(IsEmpty()){
            cout << "Stack is Empty.\n";
            return 0;
        }
        return arr[top];
        }
};
double Postfix(string exp){
    Stack s(exp.length());

    for(int i=0;i<exp.length();i++){
        char ch=exp[i];

        if(ch==' ')
        continue;

        if(isdigit(ch)){
            double num=ch-'0';
            s.push(num);
        }

        else if(ch=='+' ||ch=='-' || ch=='*' || ch=='/'  ){

            double v2=s.pop();
            double v1=s.pop();
            double res=0;

            switch (ch)
            {
            case '+':
                res=v1+v2;
                break;
            case '-':
                res=v1-v2;
                break;
            case '*':
                res=v1*v2;
                break;
            case '/':
                res=v1/v2;
                break;     
        }
        s.push(res);
    }
    else {
            cout << "Invalid character in expression: " << ch << endl;
            return 0;
        }
}
     return s.topp();
}
int main(){

    string expres;
    cout << "Enter a postfix expression (e.g., 23*54*+9-): ";
    cin >> expres;
    double result = Postfix(expres);
    cout << "\nFinal Result = " << result << endl;

return 0;
}
