#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int colourNo, vector<vector<int>> &graph,vector<int>&color)
{
    for(int i=0;i<graph.size();i++){
        if(row!=i && color[i]==colourNo && graph[i][row]==1) return false;
    }
    return true;
}

bool recursiveCall(vector<vector<int>> &graph,vector<int>&color, vector<int>&visited, int row,int m)
{
    if(graph.size()==visited.size()) return true;
    visited.push_back(row);
    for(int i=0;i<m;i++){
        if(isSafe(row,i,graph,color)){
            color[row]=i;
            if(recursiveCall(graph,color,visited,row+1,m)) return true;
            color[row]=-1;
        }
    }
    visited.pop_back();
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m)
{
    vector<int> visited;
    vector<int>colors;
    for(int i=0;i<mat.size();i++) colors[i]=-1;
    bool flag = recursiveCall(mat,colors, visited, 0,m);
    if(flag) return "YES";
    return "NO";
}
int main()
{
    int t;
    vector<string> output;
    cin>>t;
    while(t--){
        vector<vector<int>> graph;
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            vector<int> x;
            for(int j=0;j<n;j++){
                int y;
                cin>>y;
                x.push_back(y);
            }
            graph.push_back(x);
        }
        output.push_back(graphColoring(graph,m));
    }
    return 0;
}
