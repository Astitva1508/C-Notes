#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> ans(V, INT_MAX);
    vector<int> visited(V, 0);
    ans[S] = 0;
    stack<int> done;
    vector<int> visited(V,0);
    done.push(S);
    while(!done.empty()){
        int i = done.top();
        done.pop();
        for (auto j : adj[i])
        {
            if(!visited[j[0]]){
                done.push(j[0]);
                if(ans[i]+j[1]<ans[j[0]]){
                    ans[j[0]]=ans[i]+j[1];
                }
            }
        }
        visited[i]=1;
    }
    return ans;
}

int main(){
    
    return 0;
}