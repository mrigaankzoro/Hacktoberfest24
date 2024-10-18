#include <iostream>
using namespace std;

int main() {
    int n1, n2;
    char op;

    // Input two numbers
    cout << "Enter two numbers: ";
    cin >> n1 >> n2;

    // Input the operator
    cout << "Enter an operator (+, -, *, /, %): ";
    cin >> op;

    // Switch case to perform the selected operation
    switch (op) {
        case '+':
            cout << "Result: " << n1 + n2 << endl;
            break;
        case '-':
            cout << "Result: " << n1 - n2 << endl;
            break;
        case '*':
            cout << "Result: " << n1 * n2 << endl;
            break;
        case '/':
            if (n2 != 0) {
                cout << "Result: " << n1 / n2 << endl;
            } else {
                cout << "Error: Division by zero is undefined." << endl;
            }
            break;
        case '%':
            if (n2 != 0) {
                cout << "Result: " << n1 % n2 << endl;
            } else {
                cout << "Error: Division by zero is undefined." << endl;
            }
            break;
        default:
            cout << "Error: Invalid operator." << endl;
            break;
    }

    return 0;
}
