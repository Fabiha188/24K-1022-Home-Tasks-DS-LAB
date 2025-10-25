#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Stack {
private:
    int size;
    int top;
    double* arr;
public:
    Stack(int s) {
        size = s;
        top = -1;
        arr = new double[size];
    }
    ~Stack() {
        delete[] arr;
    }
    bool IsEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == size - 1;
    }
    void push(double v) {
        if (isFull()) {
            cout << "Stack overflow! Cannot push.\n";
            return;
        }
        arr[++top] = v;
    }
    double pop() {
        if (IsEmpty()) {
            cout << "Stack underflow! Expression invalid.\n";
            return 0;
        }
        return arr[top--];
    }
    double topp() {
        if (IsEmpty()) {
            cout << "Stack is Empty.\n";
            return 0;
        }
        return arr[top];
    }
};


bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}


double evaluatePrefix(string exp) {
    Stack s(exp.length());

    
    for (int i = exp.length() - 1; i >= 0; i--) {
        char ch = exp[i];

        if (ch == ' ')
            continue;

        
        if (isdigit(ch)) {
            double num = 0;
            int base = 1;

            
            while (i >= 0 && isdigit(exp[i])) {
                num = (exp[i] - '0') * base + num;
                base *= 10;
                i--;
            }
            i++; 
            s.push(num);
        }

        else if (isOperator(ch)) {
            // Pop two operands
            double v1 = s.pop();
            double v2 = s.pop();
            double res = 0;

            switch (ch) {
                case '+': res = v1 + v2; break;
                case '-': res = v1 - v2; break;
                case '*': res = v1 * v2; break;
                case '/': res = v1 / v2; break;
                case '^': res = pow(v1, v2); break;
            }
            s.push(res);
        }
        else {
            cout << "Invalid character in expression: " << ch << endl;
            return 0;
        }
    }

    return s.pop();
}

int main() {
    string expres;
    cout << "Enter a prefix expression (example: - + 2 3 * 4 5 or -+23*49): ";
    getline(cin, expres);

    double result = evaluatePrefix(expres);
    cout << "\nFinal Result = " << result << endl;

    return 0;
}









