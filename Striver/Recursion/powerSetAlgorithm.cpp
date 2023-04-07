// Generate All subsequences using the Power Set Alogrithm

#include <bits/stdc++.h>
using namespace std;

void printPowerSet(vector<vector<int>> powerSet){
    for (auto it:powerSet){
        for (int j:it){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void powerSet(vector<vector<int>> &subs,vector<int> &nums){
    vector<int>sub;
    subs.push_back(sub);
    for (int i:nums){
        vector<vector<int>> dummySubs;
        for (auto it:subs){
            it.push_back(i);
            dummySubs.push_back(it);
        }
        for(auto it:dummySubs){
            subs.push_back(it);
        }
    }
    printPowerSet(subs);
}

int main(){
    vector<int> numbers={3,1,2};
    vector<vector<int>> powerVector;
    powerSet(powerVector,numbers);
    //printPowerSet(powerVector);
    return 0;
}