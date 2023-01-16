#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<pair<int,int>> vP;
    
    int N;
    cin>>N;
    // Array of Vectors vs Vector of Vectors
    // Array of Vectors : It is a 2-D array with number of rows static
    vector<int> arrayOfVectors[N];  
    // Vector of Vectors : It is a 2-D array with both rows and columns dynamic
    vector<vector<int>> vectorOfVectors;

    // Taking Inputs for Array of vectors:
    for (int i=0;i<N;i++){
        int noOfColumns;
        cin>>noOfColumns;
        for (int j=0;j<noOfColumns;j++){
            int x;
            cin>>x;
            arrayOfVectors[i].push_back(x);
        }
    }

    // Taking Inputs for vectors of vectors
    int noOfRows;
    cin>>noOfRows;
    for(int i=0;i<noOfRows;i++){
        vector<int> vec;
        int noOfColumns;
        cin>>noOfColumns;
        for (int j=0;j<noOfColumns;j++){
            int x;cin>>x;
            vec.push_back(x);
        // Couldn't do vec[i].push_back(x) as vec does not have ith index still
        }
        vectorOfVectors.push_back(vec);
    }
    // Or
    for(int i=0;i<noOfRows;i++){
        vectorOfVectors.push_back(vector<int>());
        // vector<int> () is an empty vector
        int noOfColumns;
        cin>>noOfColumns;
        for (int j=0;j<noOfColumns;j++){
            int x;cin>>x;
            vectorOfVectors[i].push_back(x);
        
        }
    }

    return 0;
}