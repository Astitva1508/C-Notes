#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &numbers)
{
    for (auto it : numbers)
    {
        cout << it << " ";
    }
    cout << endl;
}

void printAllSubSequences(vector<int> &numbers, int index, vector<int> currentState)
{
    if (index >= numbers.size())
    {
        printVector(currentState);
        return;
    }
    currentState.push_back(numbers[index]);
    printAllSubSequences(numbers, index + 1, currentState);
    currentState.pop_back();
    return printAllSubSequences(numbers, index + 1, currentState);
}

void printAllSubSequencesII(vector<int> &numbers,int index,vector<int>&sub,vector<vector<int>>&subs){
    // printVector(sub);
    subs.push_back(sub);
    for (int i=index;i<numbers.size();i++){
        sub.push_back(numbers[i]);
        printAllSubSequencesII(numbers,i+1,sub,subs);
        sub.pop_back();
    }
}

int main()
{
    vector<int> numbers = {3, 1, 2};
    vector<vector<int>> subs;
    vector<int> sub;
    // vector<int> currentState = {};
    // printAllSubSequences(numbers, 0, currentState);
    printAllSubSequencesII(numbers,0,sub,subs);
    for (auto it:subs){
        for (auto jt:it){
            cout<<jt<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// Backtracking
// Iterative
// Bit Manipulation
