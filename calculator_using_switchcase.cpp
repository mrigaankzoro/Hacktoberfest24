#include <iostream>
using namespace std;

int main() {
    int n1, n2;
    char op;

    // Prompt user for input
    cout << "Enter two numbers: ";
    cin >> n1 >> n2;
    cout << "Enter an operator (+, -, *, /, %): ";
    cin >> op;

    switch (op) {
        case '+':
            cout << n1 + n2 << endl;
            break;
        case '-':
            cout << n1 - n2 << endl;
            break;
        case '*':
            cout << n1 * n2 << endl;
            break;
        case '/':
            // Check for division by zero
            if (n2 == 0) {
                cout << "Error: Division by zero is not allowed." << endl;
            } else {
                cout << n1 / n2 << endl;
            }
            break;
        case '%':
            // Check for division by zero
            if (n2 == 0) {
                cout << "Error: Division by zero is not allowed." << endl;
            } else {
                cout << n1 % n2 << endl;
            }
            break;
        default:
            cout << "Invalid operator" << endl;
    }

    return 0;
}
