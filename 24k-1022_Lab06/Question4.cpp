#include <iostream>
#include <string>
using namespace std;

// Function to define precedence of operators
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}


class Stack {
private:
    int size;
    int top;
    char* arr;   
public:
    Stack(int s) {
        size = s;
        top = -1;
        arr = new char[size];
    }
    ~Stack() {
        delete[] arr;
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == size - 1;
    }
    void push(char v) {
        if (isFull()) {
            cout << "Stack overflow! Cannot push.\n";
            return;
        }
        arr[++top] = v;
    }
    char pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Expression invalid.\n";
            return 0;
        }
        return arr[top--];
    }
    char topp() {
        if (isEmpty()) {
            return 0;
        }
        return arr[top];
    }
};


string infixToPostfix(string infix) {
    string postfix = "";
    Stack s(infix.length());

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

       
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            postfix += c;
        }
        
        else if (c == '(') {
            s.push(c);
        }
       
        else if (c == ')') {
            while (!s.isEmpty() && s.topp() != '(') {
                postfix += s.pop();
            }
            if (!s.isEmpty() && s.topp() == '(')
                s.pop();
        }
       
        else {
            while (!s.isEmpty() && precedence(c) <= precedence(s.topp())) {
                postfix += s.pop();
            }
            s.push(c);
        }
    }

   
    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
