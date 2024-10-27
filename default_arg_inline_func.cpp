//defaut_inline
#include <iostream>
using namespace std;

// Inline function to calculate the square of a number
inline int square(int x) {
    return x * x;
}

// Function with default arguments
 inline int multiply(int a, int b = 0, int c = 0) {
    return a * b * c;
}

int main() {
    int num;

    // Inline Function Example
    cout << "Enter a number to find its square: ";
    cin >> num;
    cout << "Square of " << num << " is: " << square(num) << endl;

    // Default Argument Function Example
    cout << "\nEnter a number to find its cube : ";
    cin >> num;
    // Calling the function by passing all arguments
    cout << "cube of " << num << " is " << multiply(num, num, num) << endl;

    return 0;
}
