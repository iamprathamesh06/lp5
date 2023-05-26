#include <bits/stdc++.h>
#include <omp.h>
#include <time.h>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(vector<int> &arr, int n)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
#pragma omp parallel for shared(arr, i);
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void display(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr;
    int n;
    double start = clock();
    cout << "Enter the number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the Element: ";
        int element;
        cin >> element;
        arr.push_back(element);
    }

    display(arr);
    bubbleSort(arr, n);
    clock_t end = clock();

    double elapsed = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
    cout << "Elapse Time in ms: " << elapsed << endl;
    display(arr);
}