#include <bits/stdc++.h>
using namespace std;

bool find(vector<string> &dictionary, string &s)
{
    for(auto &it:dictionary){
        if (it==s) return true;
    }
    return false;
}

void recursiveCall(string &s, int index, vector<string> &dictionary, vector<string> &output)
{
    if(index==s.size()){
        for(auto it:output){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
    string iterateS;
    for(int i=index;i<s.size();i++){
        iterateS.push_back(s[i]);
        if(find(dictionary,iterateS)){
            output.push_back(iterateS);
            recursiveCall(s,i+1,dictionary,output);
            output.pop_back();
        }
    }
}

void wordBreak(string &s, vector<string> &dictionary){
    vector<string>output;
    recursiveCall(s,0,dictionary,output);
}

int main(){
    vector<string> dictionary = {"god" ,"is", "now", "no", "where", "here"};
    string s = "godisnowherenowhere";
    wordBreak(s,dictionary);
    return 0;
}