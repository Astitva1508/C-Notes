#include <bits/stdc++.h>
using namespace std;

void recursiveCall(int index, vector<int> nums, vector<int> sub, vector<vector<int>> &subs, int currentSum, int target, int size){
    if(currentSum>target) return;
    if (currentSum == target) subs.push_back(sub);
    for (int i = index; i < size; i++)
    {
        if(i==index){
            sub.push_back(nums[i]);
            recursiveCall(i+1, nums, sub, subs, currentSum + nums[i], target, size);
            sub.pop_back();
        }
        else{
            if(nums[i]!=nums[i-1]){
                sub.push_back(nums[i]);
                recursiveCall(i+1, nums, sub, subs, currentSum + nums[i], target, size);
                sub.pop_back();
            }
        }
    }
}

vector<vector<int>> subsetWithDups(vector<int> &nums,int target){
    vector<vector<int>> subs;
    vector<int> sub;
    int size = nums.size();
    int numsArray[size];
    for (int i=0;i<size;i++){
        numsArray[i]=nums[i];
    }
    sort(numsArray,numsArray+size);
    for (int i=0;i<size;i++){
        nums[i]=numsArray[i];
    }
    recursiveCall(0,nums,sub,subs,0,target,nums.size());
    for (auto it:subs){
        for(int j:it){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return subs;
}



int main(){
    vector<int> nums = {2, 5, 2, 1, 2};
    subsetWithDups(nums,5);
    return 0;
}