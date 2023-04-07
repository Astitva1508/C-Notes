#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s)
{
    int size = s.size() - 1;
    int i = 0;
    while (i < size)
    {
        if (s[i] != s[size])
            return false;
        i++;
        size--;
    }
    return true;
}

void recursiveCall(string s, int index, vector<vector<string>> &subs, int size,vector<string> sub)
{
    if(index>=size){
        subs.push_back(sub);
    }
    string leftString;
    for (int i = index; i < size; i++)
    {
        leftString.push_back(s[i]);
        bool isLeftPal = checkPalindrome(leftString);
        if (isLeftPal){
            sub.push_back(leftString);
            recursiveCall(s, i + 1, subs, size,sub);
            sub.pop_back();
        }
    }
}

vector<vector<string>> partition(string s){
    vector<vector<string>> subs;
    vector<string>sub;
    recursiveCall(s,0,subs,s.size(),sub);
    return subs;
}

int main(){
    string s="aab";
    vector<vector<string>> subs = partition(s);

    for(auto it:subs){
        for (auto j:it){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
