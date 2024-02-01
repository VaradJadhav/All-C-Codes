#include <iostream>
using namespace std;

const int MAX = 100;

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;

    // Input the number of rows and columns of matrix A
    cout << "Enter the number of rows of matrix A: ";
    cin >> rowsA;
    cout << "Enter the number of columns of matrix A: ";
    cin >> colsA;

    // Input the elements of matrix A
    cout << "Enter the elements of matrix A: ";
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            cin >> A[i][j];
        }
    }

    // Input the number of rows and columns of matrix B
    cout << "Enter the number of rows of matrix B: ";
    cin >> rowsB;
    cout << "Enter the number of columns of matrix B: ";
    cin >> colsB;

    // Input the elements of matrix B
    cout << "Enter the elements of matrix B: ";
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            cin >> B[i][j];
        }
    }

    // Check if the matrices can be multiplied
    if (colsA != rowsB) {
        cout << "Matrices cannot be multiplied!" << endl;
        return 0;
    }

    // Multiply the matrices
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Print the resulting matrix
    cout << "The product of matrices A and B is: " << endl;
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
