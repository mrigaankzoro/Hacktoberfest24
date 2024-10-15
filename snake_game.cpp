#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 20;
int x, y, fruitX, fruitY, score;
vector<pair<int, int>> snake;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;
vector<pair<int, int>> obstacles;
int level = 1;
int speed = 100; // Initial speed

// Function declarations
void Setup();
void RespawnFruit();
void CreateObstacles();
void Draw();
void Input();
void Logic();
void GameOver();
void SaveHighScore(int score);
void LoadHighScore(int &highScore);

// Main function
int main() {
    srand(static_cast<unsigned int>(time(0)));
    Setup();
    
    while (dir != STOP) {
        Draw();
        Input();
        Logic();
        Sleep(speed); // Adjust for game speed
    }

    GameOver();
    return 0;
}

// Function definitions
void Setup() {
    dir = STOP;
    x = WIDTH / 2;
    y = HEIGHT / 2;
    score = 0;
    snake.clear();
    snake.push_back(make_pair(x, y));
    RespawnFruit();
    CreateObstacles();
}

void RespawnFruit() {
    do {
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
    } while (find(snake.begin(), snake.end(), make_pair(fruitX, fruitY)) != snake.end() ||
             find(obstacles.begin(), obstacles.end(), make_pair(fruitX, fruitY)) != obstacles.end());
}

void CreateObstacles() {
    obstacles.clear();
    for (int i = 0; i < level; ++i) {
        int obsX, obsY;
        do {
            obsX = rand() % WIDTH;
            obsY = rand() % HEIGHT;
        } while (find(snake.begin(), snake.end(), make_pair(obsX, obsY)) != snake.end() ||
                 (obsX == fruitX && obsY == fruitY));
        obstacles.push_back(make_pair(obsX, obsY));
    }
}

void Draw() {
    system("cls"); // Clear the console
    cout << string(WIDTH + 2, '#') << endl; // Top border

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0) cout << "#"; // Left wall

            // Drawing the snake head and body
            if (i == y && j == x)
                cout << "O"; // Snake head
            else if (i == fruitY && j == fruitX)
                cout << "F"; // Fruit
            else {
                bool isSnakePart = false;
                for (const auto& part : snake) {
                    if (part.first == j && part.second == i) {
                        cout << "o"; // Snake body
                        isSnakePart = true;
                        break;
                    }
                }
                // Drawing obstacles
                if (!isSnakePart) {
                    bool isObstacle = false;
                    for (const auto& obs : obstacles) {
                        if (obs.first == j && obs.second == i) {
                            cout << "#"; // Obstacle
                            isObstacle = true;
                            break;
                        }
                    }
                    if (!isObstacle) cout << " "; // Empty space
                }
            }

            if (j == WIDTH - 1) cout << "#"; // Right wall
        }
        cout << endl; // End of the row
    }

    cout << string(WIDTH + 2, '#') << endl; // Bottom border
    cout << "Score: " << score << " | Level: " << level << endl;
    cout << "Controls: WASD to move | P to pause | X to exit" << endl;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a': if (dir != RIGHT) dir = LEFT; break;
        case 'd': if (dir != LEFT) dir = RIGHT; break;
        case 'w': if (dir != DOWN) dir = UP; break;
        case 's': if (dir != UP) dir = DOWN; break;
        case 'p': 
            while (_getch() != 'p'); // Pause until 'p' is pressed again
            break;
        case 'x': dir = STOP; break;
        }
    }
}

void Logic() {
    int prevX = snake.empty() ? x : snake[0].first;
    int prevY = snake.empty() ? y : snake[0].second;
    snake.insert(snake.begin(), make_pair(x, y));

    switch (dir) {
    case LEFT: x--; break;
    case RIGHT: x++; break;
    case UP: y--; break;
    case DOWN: y++; break;
    default: break;
    }

    // Check if the snake eats the fruit
    if (x == fruitX && y == fruitY) {
        score += 10;
        RespawnFruit();
        if (score % 50 == 0) { // Increase level every 50 points
            level++;
            speed = max(50, speed - 10); // Speed up the game
            CreateObstacles(); // Add more obstacles
        }
    } else {
        snake.pop_back(); // Remove the last segment if not eating
    }

    // Wall collision handling
    if (x >= WIDTH) x = 0; 
    else if (x < 0) x = WIDTH - 1;
    if (y >= HEIGHT) y = 0; 
    else if (y < 0) y = HEIGHT - 1;

    // Self-collision and obstacle collision
    for (size_t i = 1; i < snake.size(); i++) {
        if (snake[i].first == x && snake[i].second == y) {
            dir = STOP; // Stop the game on collision
        }
    }
    for (const auto& obs : obstacles) {
        if (obs.first == x && obs.second == y) {
            dir = STOP; // Stop the game on collision with obstacle
        }
    }
}

void GameOver() {
    system("cls");
    cout << "Game Over!" << endl;
    cout << "Final Score: " << score << endl;
    int highScore;
    LoadHighScore(highScore);
    SaveHighScore(score);
    cout << "High Score: " << highScore << endl;
    cout << "Press any key to exit...";
    _getch();
}

void SaveHighScore(int score) {
    int highScore = 0;
    ifstream inFile("highscore.txt");
    if (inFile.is_open()) {
        inFile >> highScore;
        inFile.close();
    }
    if (score > highScore) {
        ofstream outFile("highscore.txt");
        outFile << score;
        outFile.close();
    }
}

void LoadHighScore(int &highScore) {
    ifstream inFile("highscore.txt");
    if (inFile.is_open()) {
        inFile >> highScore;
        inFile.close();
    } else {
        highScore = 0; // No high score yet
    }
}
