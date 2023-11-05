#include <bits/stdc++.h>
using namespace std;

int main(){
    int head;
    cin>>head;
    int n;
    cin>>n;
    int arr[n];
    int min = INT_MAX;
    int max = INT_MIN;
    int dist = INT_MAX;
    int f;
    int ans;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        if(arr[i]<head && head-arr[i]<dist){
            dist = head-arr[i];
            f=i;
        }
        if(arr[i]<min) min = arr[i];
        if(arr[i]>max) max = arr[i];
    }
    if(head>max){
        ans = head-min;
    }else if(head<min){
        ans = max-head;
    }else{
        ans = max-head+max-min+arr[f]-min;
    }
    return ans;
    return 0;
}