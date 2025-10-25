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
    bool IsEmpty() { return top == -1; }
    bool isFull() { return top == size - 1; }

    void push(double v) {
        if (isFull()) {
            cout << "Stack overflow!\n";
            return;
        }
        arr[++top] = v;
    }
    double pop() {
        if (IsEmpty()) {
            cout << "Stack underflow!\n";
            return 0;
        }
        return arr[top--];
    }
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

double evaluatePrefix(string exp) {
    Stack s(exp.length());

    for (int i = exp.length() - 1; i >= 0; i--) {
        char ch = exp[i];

        if (ch == ' ') continue;

        if (isdigit(ch)) {
            double num = 0;
            double base = 1;

            
            while (i >= 0 && isdigit(exp[i])) {
                num = (exp[i] - '0') * base + num;
                base *= 10;
                i--;
            }
            i++; 
            s.push(num);
        }
        else if (isOperator(ch)) {
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
            cout << "Invalid character: " << ch << endl;
            return 0;
        }
    }

    return s.pop();
}

int main() {
    string exp;
    cout << "Enter prefix expression (example: - + 23 5 49 or -+23549): ";
    getline(cin, exp);

    double result = evaluatePrefix(exp);
    cout << "\nFinal Result = " << result << endl;

    return 0;
}
