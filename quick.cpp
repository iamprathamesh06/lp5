#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            // swap
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    i++;
    int temp = arr[i];
    arr[i] = pivot;
    arr[high] = temp;

    return i;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
#pragma omp parallel sections
    {
        int pivot = partition(arr, low, high);

#pragma omp parallel section
        quickSort(arr, low, pivot - 1);
#pragma omp parallel section
        quickSort(arr, pivot + 1, high);
    }
}

int main()
{
    int arr[] = {3, 6, 3, 6, 845, 235, 56, 345, 73, 345, 73};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Sorting ";
    printArray(arr, n);
    quickSort(arr, 0, n - 1);

    cout << "After Sorting ";
    printArray(arr, n);

    return 0;
}