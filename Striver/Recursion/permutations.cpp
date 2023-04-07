#include <bits/stdc++.h>
using namespace std;

void recursiveCall2(int indice,vector<int> &nums,vector<vector<int>> &answer){
    if (indice==nums.size()){
        answer.push_back(nums);
        return;
    }
    for(int i=indice;i<nums.size();i++){
        swap(nums[indice],nums[i]);
        recursiveCall2(indice+1,nums,answer);
        swap(nums[indice],nums[i]);
    }
}

// Approach 2
vector<vector<int>> permute(vector<int> &nums)
{
    vector<int> output;
    vector<vector<int>> answer;
    recursiveCall2(0,nums,answer);
    return answer;
}


int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> output = permute(nums);
    for(auto it:output){
        for (int j:it)cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}

// Approach1
void recursiveCall1(vector<bool> numsMap, vector<int> &nums, vector<int> output, vector<vector<int>> &answer)
{
    if (output.size() == nums.size())
    {
        answer.push_back(output);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (!numsMap[i])
        {
            output.push_back(nums[i]);
            numsMap[i] = 1;
            recursiveCall1(numsMap, nums, output, answer);
            numsMap[i] = 0;
            output.pop_back();
        }
    }
}

// vector<vector<int>> permute(vector<int> &nums)
// {
//     vector<int> output;
//     vector<bool> numsMap;
//     vector<vector<int>> answer;
//     recursiveCall1(numsMap, nums, output, answer);
//     return answer;
// }