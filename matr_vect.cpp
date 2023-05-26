#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

void matrix_multiply(int matrixA[100][100], int matrixB[100][1], int r1, int r2, int c1)
{
    int ans[r1][1];
#pragma omp parallel for
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            ans[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                ans[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    cout << "Parallel Vector Matrix Multiplication : " << endl;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int r1, r2, c1;
    cout << "Enter number of rows in matrix A" << endl;
    cin >> r1;
    cout << "Enter number of columns in matrix A" << endl;
    cin >> c1;
    int matrixA[100][100];
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cin >> matrixA[i][j];
        }
    }

    cout << endl;
    cout << "Enter number of rows in matrix B" << endl;
    cin >> r2;
    int matrixB[100][1];
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            cin >> matrixB[i][j];
        }
    }
    cout << endl;

    if (c1 == r2)
    {
        // Multiplication is Possible
        matrix_multiply(matrixA, matrixB, r1, r2, c1);
    }
    else
    {
        cout << "Vector Matrix Multiplication is not Possible" << endl;
    }
    return 0;
}