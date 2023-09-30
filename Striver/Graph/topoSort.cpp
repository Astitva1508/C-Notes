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

int main(){
    
    return 0;
}