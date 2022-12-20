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

void RecursiveInsertionSort(int *arr, int n)
{
    if (n == 0)
        return;
    RecursiveInsertionSort(arr, n - 1);
    int key = arr[n];
    int j = n - 1;
    while (arr[j] > key && j >= 0)
    {
        arr[j + 1]=arr[j];
        j -= 1;
    }
    arr[j + 1] = key;
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
    RecursiveInsertionSort(arr, n - 1);
    PrintArray(arr, n);
    return 0;
}