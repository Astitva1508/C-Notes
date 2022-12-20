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

int BinarySearchForIndex(int *arr, int n, int key)
{
    int l = 0;
    int r = n;
    while (l < r)
    {
        int midIndex = (l + r) / 2;
        if (arr[midIndex] < key)
        {
            l = midIndex + 1;
        }
        else if (arr[midIndex] > key)
        {
            r = midIndex - 1;
        }
        else if (arr[midIndex] == key)
            return midIndex + 1;
    }
    if (arr[l] > key)
        return l;
    else
        return (l + 1);
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
        int desiredIndex = BinarySearchForIndex(arr, j, key);
        while (j >= desiredIndex)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
    PrintArray(arr,n);
    return 0;
}