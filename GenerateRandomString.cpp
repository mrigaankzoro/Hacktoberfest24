#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

// Function to generate a random string of a specified length
std::string generateRandomString(int length) {
    const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                  "abcdefghijklmnopqrstuvwxyz"
                                  "0123456789";
    std::string randomString;

    // Check for valid input
    if (length <= 0) {
        throw std::invalid_argument("Length should be a positive integer.");
    }

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
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Take input for the length of the random string
    std::cout << "Enter the length of the random string: ";
    if (!(std::cin >> length)) {
        std::cerr << "Invalid input. Please enter a positive integer." << std::endl;
        return 1;
    }

    // Check for valid input
    if (length <= 0) {
        std::cerr << "Length should be a positive integer." << std::endl;
        return 1;
    }

    try {
        // Generate and display the random string
        std::string randomString = generateRandomString(length);
        std::cout << "Random String: " << randomString << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
