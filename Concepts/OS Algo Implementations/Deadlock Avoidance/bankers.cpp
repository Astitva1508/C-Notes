#include <bits/stdc++.h>
using namespace std;


int main(){
    int noOfResources;
    cin>>noOfResources;
    vector<int> totalAvailable(noOfResources,0);
    vector<int> currAvailable(noOfResources, 0);
    for(int i=0;i<noOfResources;i++){
        cin>>totalAvailable[i];
        currAvailable[i] = totalAvailable[i];
    }
    int noOfProcesses;
    cin>>noOfProcesses;

    int allocated[noOfProcesses][noOfResources];
    int maxNeed[noOfProcesses][noOfResources];
    int required[noOfProcesses][noOfResources];
    // Data for allocated;
    cout<<"Enter the data for Allocated"<<endl;
    for(int i=0;i<noOfProcesses;i++){
        for(int j=0;j<noOfResources;j++){
            cin>>allocated[i][j];
            currAvailable[j]-=allocated[i][j];
        }
    }
    // Data for max Need;
    cout<<"Enter the data for Maximum Need"<<endl;
    for (int i = 0; i < noOfProcesses; i++){
        for (int j = 0; j < noOfResources; j++){
            cin >> maxNeed[i][j];
            required[i][j] = maxNeed[i][j]-allocated[i][j];
        }
    }

    cout<<"Data for the required is"<<endl;
    for (int i = 0; i < noOfProcesses; i++)
    {
        for (int j = 0; j < noOfResources; j++)
        {
            cout<<required[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Currently Available"<<endl;
    for(int i=0;i<noOfResources;i++){
        cout<<currAvailable[i]<<" ";
    }
    cout<<endl;
    unordered_set<int> safeSequence;
    while(true){
        bool isAnyFulfilled = false;
        int i=0;
        for(;i<noOfProcesses;i++){
            if(safeSequence.find(i)!=safeSequence.end()) continue;
            bool isFulfilled = true;
            for (int j = 0; j < noOfResources; j++)
            {
                if (required[i][j] > currAvailable[j])
                {
                    isFulfilled = false;
                    break;
                }
            }
            if(isFulfilled){
                isAnyFulfilled = true;
                for(int j=0;j<noOfResources;j++){
                    currAvailable[j]+=allocated[i][j];
                    required[i][j] = 0;
                }
                safeSequence.insert(i);
            }
        }
        if(!isAnyFulfilled && safeSequence.size()!=noOfProcesses){
            cout<<"DeadLock Triggered"<<endl;
            break;
        }
        else if(!isAnyFulfilled && safeSequence.size()==noOfProcesses){
            cout<<"No Deadlock"<<endl;
            break;
        }
    }
    return 0;
}

// 3
// 6 5 7
// 5
// 0 1 0 
// 2 0 0
// 3 0 2
// 2 1 1 
// 0 0 2
// 7 5 3
// 3 2 2 
// 9 0 2
// 4 2 2
// 5 3 3