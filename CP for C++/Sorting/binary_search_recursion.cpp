#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int *arr, int key,int l,int r)
{
    int midIndex = l + (r - l) / 2; // To avoid overflow
    if (l > r)
        return -1;

    if (arr[midIndex] > key)
    {
        r = midIndex - 1;
        return BinarySearch(arr,key,l,r);
    }
    else if (arr[midIndex] < key)
    {
        l = midIndex + 1;
        return BinarySearch(arr, key, l, r);
    }
    else
    {
        return midIndex;
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cin >> key;
    cout << BinarySearch(arr,key,0,n-1);
    return 0;
}