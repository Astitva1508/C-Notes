#include <bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>> &matrix)
{
    int V = matrix.size();

    // If there is no edge from u to v mark it as 1e9 (i.e not reachable)
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (matrix[i][j] == -1)
                matrix[i][j] = 1e9;

            if(i==j) matrix[i][j]=0; 
        }
    }

    // Via each vertex in graph
    for (int k = 0; k < V; k++)
    {
        //Update the distances to the most optimal
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                matrix[i][j] = min(matrix[i][k] + matrix[k][j], matrix[i][j]);
            }
        }

    }


    //For Negative Cycle Detection
    for(int i=0;i<V;i++){
        if(matrix[i][i]<0){
            // negative weight cycle detected
        }
    }

    // Step only for compatibility with GFG
    // If the minimum distance is 1e9(i.e unreachable), convert it back to -1
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (matrix[i][j] == 1e9)
                matrix[i][j] = -1;
        }
    }
}
