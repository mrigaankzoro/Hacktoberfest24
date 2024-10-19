#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char generateRandomChar() {
    int randChoice = rand() % 4;

    if (randChoice == 0)
        return 'A' + (rand() % 26);  // Uppercase letter
    else if (randChoice == 1)
        return 'a' + (rand() % 26);  // Lowercase letter
    else if (randChoice == 2)
        return '0' + (rand() % 10);  // Digit
    else
        return "!@#$%^&*()_+-=[]{}|;:,.<>?"[rand() % 20];  // Special character
}

void generatePassword(int size) {
    for (int i = 0; i < size; i++) {
        printf("%c", generateRandomChar());
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the length of the password: ");
    scanf("%d", &size);

    srand(time(NULL));  // Seed the random number generator

    printf("Generated password: ");
    generatePassword(size);

    return 0;
}
