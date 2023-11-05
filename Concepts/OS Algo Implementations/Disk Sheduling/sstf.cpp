#include <bits/stdc++.h>
using namespace std;

int main(){
    int head;
    cin>>head;
    int n;
    cin>>n;
    int x;
    vector<int> arr;
    for(int i=0;i<n;i++) {
        cin>>x;
        arr.push_back(x);
    }
    int start = head;
    
    int ans = 0;
    int index;
    while(!arr.empty()){
        int compare = INT_MAX;
        for(int i=0;i<arr.size();i++){
            if(abs(start-arr[i]<compare)){
                compare = abs(start-arr[i]);
                start = arr[i];
                index=i;
            }
        }
        ans+=compare;
        arr.erase(arr.begin()+index);
    }
    return ans;
    return 0;
}