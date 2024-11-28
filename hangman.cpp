#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

void displayWord(const string& word, const vector<char>& guessedLetters) {
    for (char letter : word) {
        if (find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end()) {
            cout << letter << ' ';
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

bool isWordGuessed(const string& word, const vector<char>& guessedLetters) {
    for (char letter : word) {
        if (find(guessedLetters.begin(), guessedLetters.end(), letter) == guessedLetters.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    // List of possible words
    const vector<string> words = {"programming", "hangman", "development", "computer", "science"};
    
    // Randomly select a word
    srand(static_cast<unsigned int>(time(0)));
    string word = words[rand() % words.size()];
    
    vector<char> guessedLetters;
    int attempts = 6; // Number of allowed incorrect attempts

    cout << "Welcome to Hangman!" << endl;

    while (attempts > 0) {
        cout << "Attempts remaining: " << attempts << endl;
        displayWord(word, guessedLetters);
        
        char guess;
        cout << "Enter a letter: ";
        cin >> guess;

        // Check if the letter has been guessed before
        if (find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end()) {
            cout << "You have already guessed that letter!" << endl;
            continue;
        }

        // Add the guessed letter to the list
        guessedLetters.push_back(guess);

        // Check if the guess is correct
        if (word.find(guess) == string::npos) {
            attempts--;
            cout << "Incorrect guess!" << endl;
        } else {
            cout << "Good guess!" << endl;
        }

        // Check if the word has been completely guessed
        if (isWordGuessed(word, guessedLetters)) {
            cout << "Congratulations! You've guessed the word: " << word << endl;
            break;
        }
    }

    if (attempts == 0) {
        cout << "You've run out of attempts! The word was: " << word << endl;
    }

    return 0;
}
