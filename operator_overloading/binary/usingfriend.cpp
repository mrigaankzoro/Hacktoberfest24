#include <iostream>
using namespace std;

class no {
private:
    int num;

public:
    // Default constructor
    no() {
        num = 0;
    }

    // Parameterized constructor
    no(int b) {
        num = b;
    }

    
    friend no operator+(no & , no &);

    
    void Display() {
        cout << "number = " << num << endl;
    }
};

// Friend function definition for overloading '+'
no operator+(no & obj1, no &  obj2) {
    no temp;
    temp.num = obj1.num + obj2.num;
    return temp;
}

int main() {
    no obj2(5), obj1(4);  // Initializing objects with values
    obj2.Display();
    obj1.Display();
    
    no obj3;  // Default object (num = 0)
    obj3.Display();

    obj3 = obj1 + obj2;  // Adding obj1 and obj2 using the friend function

    obj2.Display();
    obj1.Display();
    obj3.Display();  // Displaying the result of addition

    return 0;
}
