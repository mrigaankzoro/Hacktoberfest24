#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
string getRandomWord() {
    vector<string> words = {"hangman", "programming", "cplusplus", "challenge", "computer", "development"};
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation
    return words[rand() % words.size()];
}


void displayCurrentState(const string& word, const vector<char>& guessedLetters) {
    for (char ch : word) {
        if (find(guessedLetters.begin(), guessedLetters.end(), ch) != guessedLetters.end()) {
            cout << ch << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}


int main() {
    string word = getRandomWord();
    vector<char> guessedLetters;
    int attempts = 6; 
    bool wordGuessed = false;

    cout << "Welcome to Hangman!" << endl;

    while (attempts > 0 && !wordGuessed) {
        cout << "Attempts left: " << attempts << endl;
        cout << "Current word: ";
        displayCurrentState(word, guessedLetters);

        char guess;
        cout << "Enter a letter: ";
        cin >> guess;
        guess = tolower(guess); 
      
        if (find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end()) {
            cout << "You already guessed that letter!" << endl;
            continue;
        }

        guessedLetters.push_back(guess); 
        if (word.find(guess) != string::npos) {
            cout << "Good guess!" << endl;
        } else {
            cout << "Wrong guess!" << endl;
            attempts--;
        }
        wordGuessed = true;
        for (char ch : word) {
            if (find(guessedLetters.begin(), guessedLetters.end(), ch) == guessedLetters.end()) {
                wordGuessed = false;
                break;
            }
        }
    }

    if (wordGuessed) {
        cout << "Congratulations! You guessed the word: " << word << endl;
    } else {
        cout << "You ran out of attempts! The word was: " << word << endl;
    }

    return 0;
}
