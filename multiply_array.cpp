#include <iostream>
using namespace std;

int main() {
    int row1, col1, row2, col2;

    // Input dimensions for both matrices
    cout << "Enter rows and columns for the first matrix: ";
    cin >> row1 >> col1;
    cout << "Enter rows and columns for the second matrix: ";
    cin >> row2 >> col2;

    // Checking if multiplication is possible
    if (col1 != row2) {
        cout << "Matrix multiplication not possible with these dimensions." << endl;
        return 0;
    }

    // Declare matrices
    int mat1[row1][col1], mat2[row2][col2], result[row1][col2];

    // Input first matrix
    cout << "Enter elements of the first matrix:" << endl;
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < col1; ++j) {
            cout << "Enter element mat1[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> mat1[i][j];
        }
    }

    // Input second matrix
    cout << "Enter elements of the second matrix:" << endl;
    for (int i = 0; i < row2; ++i) {
        for (int j = 0; j < col2; ++j) {
            cout << "Enter element mat2[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> mat2[i][j];
        }
    }

    // Initialize result matrix to 0
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < col2; ++j) {
            result[i][j] = 0;
        }
    }

    // Multiply matrices
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < col2; ++j) {
            for (int k = 0; k < col1; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    // Display result
    cout << "Resultant matrix after multiplication:" << endl;
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < col2; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
