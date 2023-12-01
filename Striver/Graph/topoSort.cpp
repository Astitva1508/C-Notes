#include <bits/stdc++.h>
using namespace std;

// Applies only on Directed Acyclic Graph
// Any linear ordering of elements such that if there is an edge from u to v, then u always apears before v in the ordering.

// Topo Sort using DFS : uses stack
// Intuition : Jiska DFS complete hota jae , usko store krte jao.
// Jab given node se jaane waale saare outgoing edges traverse kar liye, tab isko bhi stack me daal sakte
// Applying Topo using DFS on Directed Cyclic Graph gives incorrect results

// Tops Sort using BFS (Kahns Algorithm)
// Additonal DS needed : Indegree Array
// Concept is that in a DAG, there is always a node whose indegree is zero
// Steps:
// Insert all nodes with indegree zero
// Time Complexity : O(V+E)
// Applying Topo on Directed Cyclic Graph gives lesser elements than number of vertices

void topo(vector<vector<pair<int, int>>> &adj)
{
    int nodes = adj.size();
    vector<int> ans;
    vector<int> inorder(nodes, 0);
    for (int i = 0; i < nodes; i++)
    {
        for (auto j : adj[i])
        {
            inorder[j.first]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < nodes; i++)
    {
        if (inorder[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto it : adj[node])
        {
            inorder[it.first]--;
            if (inorder[it.first] == 0)
                q.push(it.first);
        }
    }
}

int main()
{

    return 0;
}