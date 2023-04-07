#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> numbers = {1,2,3,4,5};
    vector<vector<int>> subArrays;
    for (int i=0;i<5;i++){
        vector<int> sub;
        for (int j=i;j<5;j++){
            sub.push_back(numbers[j]);
            subArrays.push_back(sub);
        }
    }
    for (auto it:subArrays){
        for (auto j:it){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}