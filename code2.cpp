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

void printAllSubSequences(vector<int> &numbers,int index, vector<int> currentState){
    if (index >= numbers.size()){
        printVector(currentState);
        return;
    }
    currentState.push_back(numbers[index]);
    printAllSubSequences(numbers,index+1,currentState);
    currentState.pop_back();
    return printAllSubSequences(numbers,index+1,currentState); 
}


int main(){
    vector<int> numbers = {3,1,2};
    vector<int> currentState = {};
    printAllSubSequences(numbers, 0, currentState);
    return 0;
}