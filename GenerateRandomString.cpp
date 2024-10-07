#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <string>

using namespace std;

string generateRandomString(int length) {
    const string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                              "abcdefghijklmnopqrstuvwxyz"
                              "0123456789";
    string randomString;

    // Generate random characters
    for (int i = 0; i < length; ++i) {
        int index = rand() % characters.size();
        randomString += characters[index];
    }

    return randomString;
}

int main() {
    int length;

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Take input for the length of the random string
    cout << "Enter the length of the random string: ";
    cin >> length;

    // Check for valid input
    if (length <= 0) {
        cout << "Length should be a positive integer." << endl;
        return 1;
    }

    // Generate and display the random string
    string randomString = generateRandomString(length);
    cout << "Random String: " << randomString << endl;

    return 0;
}
