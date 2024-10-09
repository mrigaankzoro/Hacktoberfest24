#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 20;
int x, y, fruitX, fruitY, score;
vector<pair<int, int>> snake;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

void Setup() {
    dir = STOP;
    x = WIDTH / 2;
    y = HEIGHT / 2;
    score = 0;
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    snake.clear();
    snake.push_back(make_pair(x, y));
}

void Draw() {
    system("cls"); // Clear the console

    for (int i = 0; i < WIDTH + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0)
                cout << "#"; // Wall on the left

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
                if (!isSnakePart)
                    cout << " ";
            }

            if (j == WIDTH - 1)
                cout << "#"; // Wall on the right
        }
        cout << endl;
    }

    for (int i = 0; i < WIDTH + 2; i++)
        cout << "#";
    cout << endl;

    cout << "Score: " << score << endl;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            dir = STOP; // Stop the game
            break;
        }
    }
}

void Logic() {
    int prevX = snake.empty() ? x : snake[0].first;
    int prevY = snake.empty() ? y : snake[0].second;
    int prev2X, prev2Y;
    snake.insert(snake.begin(), make_pair(x, y));

    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    // Check if the snake eats the fruit
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
    } else {
        snake.pop_back();
    }

    // Check for collisions with walls or self
    if (x >= WIDTH) x = 0; else if (x < 0) x = WIDTH - 1;
    if (y >= HEIGHT) y = 0; else if (y < 0) y = HEIGHT - 1;

    for (size_t i = 1; i < snake.size(); i++) {
        if (snake[i].first == x && snake[i].second == y) {
            dir = STOP; 
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    Setup();
    
    while (dir != STOP) {
        Draw();
        Input();
        Logic();
        Sleep(100);
    }

    return 0;
}
