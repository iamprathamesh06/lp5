#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

void min_reduction(vector<int> &arr)
{
    int min_value = arr[0];
#pragma omp parallel for reduction(min : min_value)
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < min_value)
        {
            min_value = arr[i];
        }
    }
    cout << "Min Value: " << min_value << endl;
}

void max_reduction(vector<int> &arr)
{
    int max_value = arr[0];
#pragma omp parallel for reduction(max : max_value)
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > max_value)
        {
            max_value = arr[i];
        }
    }
    cout << "Max Value: " << max_value << endl;
}

void sum_reduction(vector<int> &arr)
{
    int sum = 0;
#pragma omp parallel for reduction(+ : sum)
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    cout << "Sum: " << sum << endl;
}

void average_reduction(vector<int> &arr)
{
    int sum = 0;
#pragma omp parallel for reduction(+ : sum)
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    double average = sum / arr.size();
    cout << "Average: " << average << endl;
}

int main()
{

    vector<int> arr;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    while (n--)
    {
        cout << "Enter the element: ";
        int element;
        cin >> element;
        arr.push_back(element);
    }

    cout << "*****************OUTPUT*****************" << endl;

    min_reduction(arr);
    max_reduction(arr);
    sum_reduction(arr);
    average_reduction(arr);

    cout << "******************END*******************" << endl;

    return 0;
}