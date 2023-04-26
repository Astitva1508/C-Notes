#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void PrintArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
}

void bubbleSortFunction(int *arr, int n)
{
    if (n == 1)
        return;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            swap(arr + i, arr + i + 1);
    }
    bubbleSortFunction(arr, n - 1);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bubbleSortFunction(arr, n);
    PrintArray(arr, n);
    return 0;
}