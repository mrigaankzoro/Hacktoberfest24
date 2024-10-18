#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void displayWord(const vector<char>& word, const vector<bool>& guessed) {
    for (int i = 0; i < word.size(); i++) {
        if (guessed[i]) {
            cout << word[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

bool isWordGuessed(const vector<bool>& guessed) {
    for (bool guessedChar : guessed) {
        if (!guessedChar) return false;
    }
    return true;
}

int main() {
    string wordToGuess = "hangman";
    vector<char> word(wordToGuess.begin(), wordToGuess.end());
    vector<bool> guessed(wordToGuess.length(), false);
    vector<char> wrongGuesses;
    int maxTries = 6;
    int tries = 0;

    cout << "Welcome to Hangman Game!" << endl;

    while (tries < maxTries) {
        cout << "\nCurrent word: ";
        displayWord(word, guessed);
        cout << "Wrong guesses: ";
        for (char ch : wrongGuesses) cout << ch << " ";
        cout << endl;

        char guess;
        cout << "Guess a letter: ";
        cin >> guess;
        guess = tolower(guess); // Convert to lowercase

        // Check if the letter is already guessed
        if (find(wrongGuesses.begin(), wrongGuesses.end(), guess) != wrongGuesses.end() || 
            find(guessed.begin(), guessed.end(), guess) != guessed.end()) {
            cout << "You already guessed that letter!" << endl;
            continue;
        }

        // Check if the guessed letter is in the word
        bool found = false;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == guess) {
                guessed[i] = true;
                found = true;
            }
        }

        // If the letter was not found, add it to wrong guesses
        if (!found) {
            wrongGuesses.push_back(guess);
            tries++;
            cout << "Incorrect guess! You have " << maxTries - tries << " tries left." << endl;
        }

        // Check if the word is fully guessed
        if (isWordGuessed(guessed)) {
            cout << "\nCongratulations! You've guessed the word: ";
            displayWord(word, guessed);
            break;
        }
    }

    // If the user runs out of tries
    if (tries == maxTries) {
        cout << "\nGame Over! The word was: " << wordToGuess << endl;
    }

    return 0;
}
