#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int *arr,int n,int key){
    int l=0;int r=n-1;
    while (l<=r){
        int midIndex = l+(r-l)/2; //To avoid overflow
        if (arr[midIndex]>key){
            r=midIndex-1;
        }else if(arr[midIndex]<key){
            l=midIndex+1;
        }else{
            return midIndex;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin>> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    int key;
    cin>>key;
    cout<<BinarySearch(arr,n,key);
    return 0;
}