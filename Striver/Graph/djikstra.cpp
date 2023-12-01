#include <bits/stdc++.h>
using namespace std;

// Can be implemented using set, priority-queue as well as plain BFS
// Priority Queue is the most used approach

// Data Structures used : 
    // Priority Queue
    // Distance Array

// Dijkstra does not work for graphs having single negative wt and graphs having negative weight cycle

// Time Complexity : ElogV

void Dijkstra(vector<vector<pair<int, int>>> &adj, int src)
{
    int nodes = adj.size();
    vector<int> dist(nodes, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    // distance, node

    while (!pq.empty())
    {
        int u = pq.top().second;
        int distance = pq.top().first;
        pq.pop();
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

