#include <bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

int knapsack(int n,int W,vector<int>&wt,vector<int>&val){

    //Tabul
    vector<vector<int>>dp(n,vector<int>(W+1,0));
    if(wt[0]<=W) dp[0][wt[0]] = val[0];
    int maxAns = INT_MIN;
    for(int i=1;i<n;i++){
        for(int j=1;j<=W;j++){
            dp[i][j] = dp[i-1][j];
            if(j>=wt[i]) dp[i][j] = max(dp[i][j],dp[i-1][j-wt[i]]+val[i]);

            maxAns = max(maxAns,dp[i][j]);
        }
    }
    return maxAns;


    // Memoization
    return solve(0,W,wt,val,n);
}

int solve(int index,int W,vector<int>&wt,vector<int>&val,int N){
    if(index==N || W<=0) return 0;

    if(W<wt[0]) return solve(index+1,W,wt,val,N);

    return max(solve(index + 1, W, wt, val, N), solve(index + 1, W-wt[index],wt, val, N)+val[index]);
}
