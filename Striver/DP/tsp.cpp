#include <bits/stdc++.h>
using namespace std;


int tabul(vector<vector<int>>&cost,int n){
    int max = 1<<n;
    vector<vector<int>>dp(n,vector<int>(max+1,1e5));

    dp[0][1] = 0;

    for(int k=1;k<max;k++){
        for(int i=0;i<n;i++){
            if(k&(1<<i)){
                for (int j = 0; j < n; j++)
                {
                    if(cost[i][j]!=0 && !(k&(1<<j))){
                        dp[j][k|(1<<j)] = min(dp[j][k|(1<<j)],dp[i][k]+cost[i][j]);
                    }
                }
            }
            
        }
    }

    int ans = 1e5;
    for(int i=1;i<n;i++){
        if(cost[i][0]!=0){
            ans = min(ans,dp[i][max-1]+cost[i][0]);
        }
    }
    return ans;
}

int main(){
    return 0;
}