#include <bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

int recur(string &s1,string &s2,int i,int j){
    if(i==s1.size() || j==s2.size()) return 0;
    if(s1[i]==s2[j]) return 1+recur(s1,s2,i+1,j+1);
    else return max(recur(s1,s2,i+1,j),recur(s1,s2,i,j+1));
}

int tabul(string &s1 ,string& s2){
    vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
    int n = s1.size();
    int m = s2.size();
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(s1[i]==s2[j]) dp[i][j] = 1+dp[i+1][j+1];
            else dp[i][j] = max(dp[i][j+1],dp[i+1][j]);
        }
    }
}