#include <bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}

bool isSafe(int node,int c,vector<vector<int>>&adj,vector<int>&colorsAssigned){
    for(auto it:adj[node]) if(colorsAssigned[it]==c) return false;
    return true;
}

bool ans(int node,int m,vector<int>colorAssigned,vector<vector<int>>&adj){
    if(node==adj.size()) return true;
    for(int i=0;i<m;i++){
        if(isSafe(node,i,adj,colorAssigned)){
            colorAssigned[node]=i;
            if(ans(node,m,colorAssigned,adj))  return true;
            colorAssigned[node]=-1;
        }
    }
    return false;
}