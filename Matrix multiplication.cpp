#include <iostream>
using namespace std;

void inputMatrix(int matrix[][10], int rows, int cols) {
    cout << "Enter elements of the matrix (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }
}

void multiplyMatrices(int first[][10], int second[][10], int result[][10], int firstRows, int firstCols, int secondCols) {
    for (int i = 0; i < firstRows; ++i) {
        for (int j = 0; j < secondCols; ++j) {
            result[i][j] = 0; // Initialize the result matrix element
            for (int k = 0; k < firstCols; ++k) {
                result[i][j] += first[i][k] * second[k][j]; // Perform multiplication
            }
        }
    }
}

void displayMatrix(int matrix[][10], int rows, int cols) {
    cout << "Resultant Matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int first[10][10], second[10][10], result[10][10];
    int firstRows, firstCols, secondRows, secondCols;

    // Input dimensions for the first matrix
    cout << "Enter rows and columns for the first matrix: ";
    cin >> firstRows >> firstCols;

    // Input the first matrix
    inputMatrix(first, firstRows, firstCols);

    // Input dimensions for the second matrix
    cout << "Enter rows and columns for the second matrix: ";
    cin >> secondRows >> secondCols;

    // Check if multiplication is possible
    if (firstCols != secondRows) {
        cout << "Error: Number of columns in the first matrix must be equal to the number of rows in the second matrix." << endl;
        return 1; // Exit the program
    }

    // Input the second matrix
    inputMatrix(second, secondRows, secondCols);

    // Multiply matrices
    multiplyMatrices(first, second, result, firstRows, firstCols, secondCols);

    // Display the result
    displayMatrix(result, firstRows, secondCols);

    return 0;
}
