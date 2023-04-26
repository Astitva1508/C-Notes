#include <bits/stdc++.h>
using namespace std;

// Our approach is to divide the array into two subarrays
// The sorted one on the left and the unsorted one on the right

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

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (arr[j] > key && j >= 0)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
    PrintArray(arr, n);
    return 0;
}