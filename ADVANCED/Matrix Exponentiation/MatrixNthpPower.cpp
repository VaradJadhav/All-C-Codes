#include <iostream>
using namespace std;

const int MAX = 100;

// Function to multiply two matrices A and B
void multiply(int A[][MAX], int B[][MAX], int C[][MAX], int n) {
    int temp[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = 0;
            for (int k = 0; k < n; k++) {
                temp[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = temp[i][j];
        }
    }
}

// Function to find the nth power of a matrix A
void matrix_power(int A[][MAX], int n, int result[][MAX]) {
    // Initialize the result matrix to the identity matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                result[i][j] = 1;
            } else {
                result[i][j] = 0;
            }
        }
    }

    // Multiply the matrix A with itself n times
    while (n > 0) {
        if (n % 2 == 1) {
            multiply(result, A, result, n);
        }
        multiply(A, A, A, n);
        n /= 2;
    }
}

int main() {
    int A[MAX][MAX], result[MAX][MAX];
    int n;

    // Input the matrix A and the value of n
    cout << "Enter the dimensions of the square matrix A: ";
    int m;
    cin >> m;
    cout << "Enter the elements of matrix A: ";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    cout << "Enter the value of n: ";
    cin >> n;

    // Compute the nth power of matrix A
    matrix_power(A, n, result);

    // Print the resulting matrix
    cout << "The " << n << "-th power of matrix A is: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
