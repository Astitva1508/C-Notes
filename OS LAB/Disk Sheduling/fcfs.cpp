#include <bits/stdc++.h>
using namespace std;

int main(){
    int head;
    cin>>head;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=abs(head-arr[i]);
        head = arr[i];
    }
    return ans;
    return 0;
}