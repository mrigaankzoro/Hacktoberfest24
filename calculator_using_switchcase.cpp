#include <iostream>
using namespace std;

int main() {
    char operation;
    double num1, num2, result;

    // Displaying the menu
    cout << "Welcome to the Simple Calculator!" << endl;
    cout << "Enter the operation you want to perform (+, -, *, /): ";
    cin >> operation;

    // Input the two numbers
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Performing the operation based on user input
    switch (operation) {
        case '+':
            result = num1 + num2;
            cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
            break;
        case '-':
            result = num1 - num2;
            cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
            break;
        case '*':
            result = num1 * num2;
            cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
            break;
        case '/':
            // Checking for division by zero
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Error: Invalid operation!" << endl;
            break;
    }

    return 0;
}
