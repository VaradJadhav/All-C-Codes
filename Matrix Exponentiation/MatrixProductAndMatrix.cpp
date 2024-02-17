#include <iostream>
using namespace std;

const int MAX = 100;

int main() {
    int A[MAX][MAX], AB[MAX][MAX], B[MAX][MAX];
    int m, n, p;

    // Input the dimensions and elements of matrix A
    cout << "Enter the number of rows of matrix A: ";
    cin >> m;
    cout << "Enter the number of columns of matrix A: ";
    cin >> n;
    cout << "Enter the elements of matrix A: ";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    // Input the dimensions and elements of matrix AB
    cout << "Enter the number of columns of matrix B: ";
    cin >> p;
    cout << "Enter the elements of matrix AB: ";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cin >> AB[i][j];
        }
    }

    // Find the second matrix B
    for (int j = 0; j < p; j++) {
        // Compute the j-th column of AB
        int C[MAX];
        for (int i = 0; i < m; i++) {
            C[i] = AB[i][j];
        }

        // Solve the linear system Ax = C for x (which is the j-th column of B)
        for (int k = 0; k < p; k++) {
            B[k][j] = 0;
            for (int i = 0; i < n; i++) {
                B[k][j] += A[k][i] * C[i];
            }
        }
    }

    // Print the resulting matrix B
    cout << "The second matrix B is: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
