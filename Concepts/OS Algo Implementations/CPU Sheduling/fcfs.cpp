#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arrival[n];
    int burst[n];
    for(int i=0;i<n;i++){
        cin>>arrival[i]>>burst[i];
    }
    int totalCPUTime = burst[0];
    int totalWaitTime = 0;
    int currProcessWaitTime = 0;
    for(int i=1;i<n;i++){
        currProcessWaitTime = totalCPUTime-arrival[i];
        if(currProcessWaitTime>0) totalWaitTime+=currProcessWaitTime;
        totalCPUTime+=burst[i];
    }

    // Assuming arrival time for first process is zero
    // Else update arrival time for all processes relative to the first process
    return 0;
}