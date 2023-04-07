#include<bits/stdc++.h>
using namespace std;

void recursiveCall(int index, vector<int> sub, vector<int> &nums, int size, vector<vector<int>> &subs)
{
    subs.push_back(sub);
    for (int i = index; i < size; i++)
    {
        if (i != index && nums[i]==nums[i-1])
        {
            sub.push_back(nums[i]);
            recursiveCall(i + 1, sub, nums, size, subs);
            sub.pop_back();
        }
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    int size = nums.size();
    sort(nums.begin(),nums.end());
    vector<int> sub;
    vector<vector<int>> subs;
    recursiveCall(0, sub, nums, size, subs);
    for (auto it : subs)
    {
        for (int j : it)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return subs;
}

int main(){
    vector<int> nums = {1,2,2,3};
    subsetsWithDup(nums);
    return 0;
}