#include <iostream>
#include <vector>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()

using namespace std;

// Function to display the current state of the guessed word
void displayWord(const string &word, const vector<bool> &guessed) {
    for (int i = 0; i < word.length(); i++) {
        if (guessed[i]) {
            cout << word[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

// Function to check if the player has won
bool isWordGuessed(const vector<bool> &guessed) {
    for (bool b : guessed) {
        if (!b) return false;
    }
    return true;
}

// Main hangman game function
void playHangman() {
    // List of possible words
    vector<string> words = {"hangman", "programming", "cpp", "games", "computer"};

    // Seed for random number generation
    srand(static_cast<unsigned int>(time(0)));

    // Randomly select a word from the list
    string word = words[rand() % words.size()];
    
    // Vector to track guessed letters
    vector<bool> guessed(word.length(), false);

    int lives = 6;  // Maximum wrong guesses allowed
    char guess;
    vector<char> wrongGuesses;

    cout << "Welcome to Hangman! You have " << lives << " lives to guess the word.\n";

    // Main game loop
    while (lives > 0) {
        cout << "\nWord: ";
        displayWord(word, guessed);
        cout << "Lives remaining: " << lives << endl;

        // Display wrong guesses
        cout << "Wrong guesses: ";
        for (char c : wrongGuesses) {
            cout << c << " ";
        }
        cout << endl;

        // Take input from the player
        cout << "Enter a letter: ";
        cin >> guess;

        // Check if the guess is correct
        bool correctGuess = false;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == guess) {
                guessed[i] = true;
                correctGuess = true;
            }
        }

        // If the guess is wrong
        if (!correctGuess) {
            wrongGuesses.push_back(guess);
            lives--;
            cout << "Wrong guess! You lost a life.\n";
        }

        // Check if the word is fully guessed
        if (isWordGuessed(guessed)) {
            cout << "Congratulations! You guessed the word: " << word << endl;
            return;
        }
    }

    // If the player runs out of lives
    cout << "Game over! The word was: " << word << endl;
}

int main() {
    playHangman();
    return 0;
}
