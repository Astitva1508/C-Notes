#include <bits/stdc++.h>
using namespace std;

bool Compare(vector<int>&v1,vector<int>&v2){
    return v1[2]<v2[2];
}



class DisjointSetBySize
{
    vector<int> parent, sizes;

public:
    DisjointSetBySize(int nodes)
    {
        sizes.resize(nodes + 1, 1); // To take into account one based indexing
        parent.resize(nodes + 1, 0);
        for (int i = 0; i < nodes + 1; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv)
            return;
        if (sizes[pu] >= sizes[pv])
        {
            sizes[pu] += sizes[pv];
            parent[pv] = pu;
        }
        else
        {
            sizes[pv] += sizes[pu];
            parent[pu] = pv;
        }
        return;
    }
};

// Prerequisite : Disjoint Set
// Algo:
//  Sort all the edges
//  Traverse through the edges and if they do not have the same ultimate parent, connect them, add the pair to the MST List, and update the sum

// Time Complexity : ElogE + E*4*alpha

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    sort(edges.begin(), edges.end(),Compare);
    DisjointSetBySize *ds = new DisjointSetBySize(n);
    vector<pair<int,int>>MST;
    int sum = 0;
    for(int i=0;i<edges.size();i++){
        if(ds->findUPar(edges[i][0])!=ds->findUPar(edges[i][1])){
            sum+=edges[i][2];
            MST.push_back({edges[i][0],edges[i][1]});
            ds->unionBySize(edges[i][0],edges[i][1]);
        }
    }
    return sum;
}