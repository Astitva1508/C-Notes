#include <bits/stdc++.h>
using namespace std;

int recur(vector<int>&cost,int i,int j){

    int ans = INT_MAX;
    for(int k = i;k<j;j++){
        ans = min(ans,cost[i-1]*cost[k]*cost[j]+recur(cost,i,k)+recur(cost,k+1,j));
    }
    return ans;
}

int tabul(vector<int>&cost,int N){
    vector<vector<int>>dp(N,vector<int>(N,1e5));
    for(int i=0;i<N;i++) dp[i][i] = 0;
    for(int i=N-1;i>=1;i--){
        for(int j=i+1;j<N;j++){
            for(int k = i;k<j;j++){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+cost[i-1]*cost[k]*cost[j]);
            }
        }
    }
    return dp[1][N-1];
}
int main(){
    
    return 0;
}