#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int arr[N];
int dp[N];

// int frog1(int n){
//     if (n==1) return 0;
//     if (dp[n]!=0){
//         return dp[n];
//     }
//     int first = (dp[n-1]==0?frog1(n-1):dp[n-1])+abs(arr[n]-arr[n-1]);
//     int second = (dp[n-2]==0?frog1(n-2):dp[n-2])+abs(arr[n]-arr[n-2]);
//     return dp[n] = min(first,second);
// }

int frog1(int n){
    if (dp[n]==0) return 0;
    if (dp[n] != -1) return dp[n];
}




int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>arr[i];
    }
    return 0;
}