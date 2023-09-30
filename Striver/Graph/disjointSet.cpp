#include <bits/stdc++.h>
using namespace std;

void theory();

// Union by Rank
class DisjointSetByRank{
    vector<int>parent,rank;
    public:
    DisjointSetByRank(int nodes){
        rank.resize(nodes+1,0); //To take into account one based indexing
        parent.resize(nodes+1,0);
        for(int i=0;i<nodes+1;i++){
            parent[i]=i;
        }
    }

    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUPar(parent[node]);
    }

    void unionByRank(int u,int v){
        int pu = findUPar(u);
        int pv = findUPar(v);
        if(pu==pv) return;
        if(rank[pu]==rank[pv]){
            rank[pu]++;
            parent[pv]=pu;
        }else if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }else{
            parent[pu]=pv;
        }
    }
};

// Union by Size
// The size array stores the number of components corresponding to the parent
class DisjointSetBySize{
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
            sizes[pu]+=sizes[pv];
            parent[pv] = pu;
        }
        else
        {
            sizes[pv]+=sizes[pu];
            parent[pu] = pv;
        }
    }
};

int main(){
    return 0;
}

void theory(){
//Usually used in Dynamic Graphs

//Functionalities : Finding the Parent
//                  Union(By Rank / By Size)

// Answers whether u and v belong to the same component in constant time = O(4 * alpha)
// To find Union of(u, v) : 1. find the ultimate parent of u and v(pu and pv)
//                          2. find the rank of pu and pv 
//                          3. connect smaller rank parent to larger one.(If both have equal, then connect anyone to other) and update the ranks of pu and pv

// Two nodes belong to the same component if they have the same ultimate parent 

// While finding the parent of a node,we do path compression.The parents are changed to the ultimate parent during path compression but the ranks are not changed.

// Why connect node with smaller rank to node with higher rank? helps to reduce the time traversed for finding the ultimate parent
}