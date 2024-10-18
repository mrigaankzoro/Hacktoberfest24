#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to select a random word from a list
string selectRandomWord(const vector<string>& wordList) {
    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % wordList.size();
    return wordList[randomIndex];
}

// Function to display the current progress of the word
void displayWordProgress(const string& word, const string& guessedLetters) {
    for (char c : word) {
        if (guessedLetters.find(c) != string::npos) {
            cout << c << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

// Main Game Loop
int main() {
    vector<string> wordList = {"hangman", "programming", "computer", "cpp"};
    string word = selectRandomWord(wordList);
    string guessedLetters = "";
    int maxWrongGuesses = 6;
    int wrongGuesses = 0;
    bool gameOver = false;

    cout << "Welcome to Hangman!" << endl;

    while (!gameOver) {
        cout << "Word: ";
        displayWordProgress(word, guessedLetters);
        
        // Player makes a guess
        cout << "Enter your guess: ";
        char guess;
        cin >> guess;

        // Check if guess is in the word
        if (word.find(guess) != string::npos) {
            guessedLetters += guess;
        } else {
            wrongGuesses++;
            cout << "Incorrect! You have " << maxWrongGuesses - wrongGuesses << " guesses left." << endl;
        }

        // Check win/loss condition
        bool allGuessed = true;
        for (char c : word) {
            if (guessedLetters.find(c) == string::npos) {
                allGuessed = false;
                break;
            }
        }

        if (allGuessed) {
            cout << "Congratulations! You've guessed the word: " << word << endl;
            gameOver = true;
        } else if (wrongGuesses >= maxWrongGuesses) {
            cout << "Game over! The correct word was: " << word << endl;
            gameOver = true;
        }
    }

    return 0;
}
