#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std; // This will remove the need to write std:: each time

// Function to display the word with underscores for unguessed letters
void displayWord(const string& word, const vector<bool>& guessed) {
    for (size_t i = 0; i < word.length(); ++i) {
        if (guessed[i]) {
            cout << word[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

// Function to display the current state of the hangman
void displayHangman(int attempts) {
    switch (attempts) {
        case 6: cout << "  +---+\n      |\n      |\n      |\n     ===\n"; break;
        case 5: cout << "  +---+\n  O   |\n      |\n      |\n     ===\n"; break;
        case 4: cout << "  +---+\n  O   |\n  |   |\n      |\n     ===\n"; break;
        case 3: cout << "  +---+\n  O   |\n /|   |\n      |\n     ===\n"; break;
        case 2: cout << "  +---+\n  O   |\n /|\\  |\n      |\n     ===\n"; break;
        case 1: cout << "  +---+\n  O   |\n /|\\  |\n /    |\n     ===\n"; break;
        case 0: cout << "  +---+\n  O   |\n /|\\  |\n / \\  |\n     ===\n"; break;
    }
}

// Function to check if the word has been fully guessed
bool isWordGuessed(const vector<bool>& guessed) {
    for (size_t i = 0; i < guessed.size(); ++i) {
        if (!guessed[i]) return false;
    }
    return true;
}

int main() {
    const vector<string> words = {"programming", "hangman", "cplusplus", "challenge", "development"};
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation
    string chosenWord = words[rand() % words.size()]; // Choose a random word
    vector<bool> guessed(chosenWord.length(), false); // Track guessed letters
    int attempts = 6;
    char guess;

    cout << "Welcome to Hangman!" << endl;

    while (attempts > 0) {
        cout << "\nAttempts left: " << attempts << endl;
        displayHangman(attempts);
        displayWord(chosenWord, guessed);
        cout << "Enter a letter: ";
        cin >> guess;

        // Check if the guessed letter is in the word
        bool correctGuess = false;
        for (size_t i = 0; i < chosenWord.length(); ++i) {
            if (chosenWord[i] == guess) {
                guessed[i] = true;
                correctGuess = true;
            }
        }

        if (!correctGuess) {
            --attempts;
            cout << "Incorrect guess!" << endl;
        }

        if (isWordGuessed(guessed)) {
            cout << "Congratulations! You've guessed the word: " << chosenWord << endl;
            break;
        }
    }

    if (attempts == 0) {
        cout << "Sorry, you've run out of attempts! The word was: " << chosenWord << endl;
        displayHangman(attempts); // Show final hangman state
    }

    return 0;
}
