#include <bits/stdc++.h>
using namespace std;

// Crux of Bellman Ford is that it relaxes the edges for N-1 times

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    vector<int> dist(V, 1e8);
    dist[S] = 0;

    // Relaxing for N-1 times 
    for (int i = 0; i < V - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if (dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    // Check for -ve weight cycle
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int w = it[2];
        // If relaxation is still taking place at the ith iteration
        if (dist[u] + w < dist[v])
        {
            return {-1};
        }
    }
    return dist;
}