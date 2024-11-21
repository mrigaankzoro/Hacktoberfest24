#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string selectRandomWord() {
    vector<string> words = {"hangman", "programming", "cplusplus", "development", "computer"};
    srand(static_cast<unsigned int>(time(0)));
    return words[rand() % words.size()];
}

void displayCurrentState(const string& word, const vector<char>& guessedLetters) {
    for (char letter : word) {
        if (find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end()) {
            cout << letter << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

int main() {
    string word = selectRandomWord();
    vector<char> guessedLetters;
    int attempts = 6;

    cout << "Welcome to Hangman!" << endl;

    while (attempts > 0) {
        cout << "Attempts remaining: " << attempts << endl;
        cout << "Current word: ";
        displayCurrentState(word, guessedLetters);

        cout << "Guess a letter: ";
        char guess;
        cin >> guess;

        if (find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end()) {
            cout << "You already guessed that letter." << endl;
            continue;
        }

        guessedLetters.push_back(guess);

        if (word.find(guess) == string::npos) {
            attempts--;
            cout << "Incorrect guess!" << endl;
        } else {
            cout << "Good guess!" << endl;
        }

        bool allGuessed = true;
        for (char letter : word) {
            if (find(guessedLetters.begin(), guessedLetters.end(), letter) == guessedLetters.end()) {
                allGuessed = false;
                break;
            }
        }

        if (allGuessed) {
            cout << "Congratulations! You've guessed the word: " << word << endl;
            break;
        }
    }

    if (attempts == 0) {
        cout << "Game Over! The word was: " << word << endl;
    }

    return 0;
}
