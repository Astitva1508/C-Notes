#include <bits/stdc++.h>
using namespace std;

//DS Needed  
//  1. Priority Queue storing the {wt,{node, parent}}
//  2. Visited Array
//  3. MST List to store all the edges which are a part of MST
//  4. sum variable to give the sum of the MST

// Time Complexity : ElogE for the outer loop + ElogE for the inner loop

class Compare
{
public:
    bool operator()(pair<int, pair<int, int>> &p1, pair<int, pair<int, int>> &p2)
    {
        return (p1.first > p2.first);
    }
};

int spanningTree(int n, vector<vector<int>> adj[])
{
    int src = 0;
    int sum = 0;
    vector<pair<int, int>> MST;
    vector<int> visited(n, 0);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare> pq;

    pq.push({0, {0, -1}});
    while (!pq.empty())
    {
        int dist = pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;
        pq.pop();
        if (visited[node])
            continue;
        visited[node] = 1;
        sum += dist;
        if (parent != -1)
            MST.push_back({node, parent});

        for (auto &it : adj[node])
        {
            if (!visited[it[0]])
            {
                pq.push({it[1], {it[0], node}});
            }
        }
    }
    return sum;
}

