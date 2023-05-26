#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

void matrix_multiplication(int A[10][10], int B[10][10], int C[10][10], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
#pragma omp parallel for
        for (int j = 0; j < col; j++)
        {
            C[i][j] = 0;
#pragma omp parallel for
            for (int k = 0; k < col; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void display(int matrix[10][10], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int A[10][10], B[10][10], C[10][10];
    int row, col;

    cout << "Enter values of rows and columns: ";

    cin >> row >> col;

    cout << "Enter First Matrix Values (Row wise)" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter First Matrix Values (Row wise)" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> B[i][j];
        }
    }

    cout << "Multiplication of Matrix: " << endl;

    matrix_multiplication(A, B, C, row, col);

    cout << "Matrix A: " << endl;
    display(A, row, col);
    cout << "Matrix B: " << endl;
    display(B, row, col);
    cout << "Matrix C (Multiplication): " << endl;
    display(C, row, col);
    return 0;
}