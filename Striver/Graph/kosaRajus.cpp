#include <bits/stdc++.h>
using namespace std;

void theory();

class Solution
{
    void dfs(int node, vector<int> &visited, stack<int> &st, vector<vector<int>> &adj)
    {
        for (auto &it : adj[node])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                dfs(it, visited, st, adj);
            }
        }
        st.push(node);
    }
    void dfs(int node, vector<int> &visited, vector<vector<int>> &adj,vector<int>&currSCC)
    {
        for (auto &it : adj[node])
        {
            if (!visited[it])
            {
                currSCC.push_back(it);
                visited[it] = 1;
                dfs(it, visited, adj,currSCC);
            }
        }
    }

public:
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        stack<int> st;
        // To have the correct order of traversing nodes;

        vector<int> visited(V, 0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                visited[i]=1;
                dfs(i,visited,st,adj);
            }
        }

        for (int i = 0; i < V; i++)
            visited[i] = 0;

        // Reverse the graph
        vector<vector<int>> revAdj(V);
        for (int i = 0; i < adj.size(); i++)
        {
            for (auto j : adj[i])
            {
                revAdj[j].push_back(i);
            }
        }

        int ct = 0;
        vector<vector<int>> SCC;
        while (!st.empty())
        {
            int top = st.top();
            st.pop();
            if (!visited[top])
            {
                visited[top] = 1;
                vector<int>currSCC={top};
                dfs(top, visited, revAdj,currSCC);
                ct++;
                SCC.push_back(currSCC);
            }
        }
        return ct;
    }
};

void theory(){
    // Kosaraju's Algo used to find Strongly Connected Components(SCC)

    // Possible Questions :
    // Figure out the number of SCC's
    // Print the SCC
    // Strongly Connected Components are only applicable to connected graphs

    // A component of a graph is called Strongly Connected if every pair of vertices is reachable to each other

    // Observation :
    // In the original graph, all the (strongly connected components) are connected to each other which means there is an edge from one strongly connected component to other
    // SCC1->SCC2->SCC3->SCC4

    // if we reverse these edges, all the strongly connected components become disconnected
    // SCC1<-SCC2<-SCC3<-SCC4

    // But we dont know which edges to reverse? then reverse the entire graph... The SCC's dont change even after that but the adjacent SCC's become not reachable
    // However, the starting node is the key. If the node we start to traverse from is in SCC1 , then we get all the SCC's. But if it is in SCC4(for example), then the problem stays where it was

    // This problem is resolved using the concept of Starting Time and Finishing Time

    // Algo:
    // sort all the edges according to finishing time(DFS + stack)
    // The above step makes sure that the node which finishes last(top of the stack) is the part of the last SCC component(in the reversed graph) and node which finished first is part of the first SCC component.

    // reverse the graph
    // do a DFS

    // Time Complexity of all the three steps is V+E
    // Algo Time Complexity : O(V+E)
}

