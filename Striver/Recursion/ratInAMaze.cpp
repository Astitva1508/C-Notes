#include <bits/stdc++.h>
using namespace std;

void recursiveCall(int rowNo, int colNo, vector<vector<int>> &m, string&moves, vector<string> &output, int n,set<pair<int,int>> doneMoves)
{
    if(doneMoves.find({rowNo,colNo})!=doneMoves.end()) return;
    if (rowNo == n - 1 && colNo == n - 1)
    {
        output.push_back(moves);
        return;
    }
    doneMoves.insert({rowNo,colNo});
    if(rowNo>=1 && m[rowNo-1][colNo]==1){
        moves.push_back('U');
        recursiveCall(rowNo-1,colNo,m,moves,output,n,doneMoves);
        moves.pop_back();
    }
    if(rowNo<n-1 && m[rowNo+1][colNo]==1){
        moves.push_back('D');
        recursiveCall(rowNo+1,colNo,m,moves,output,n,doneMoves);
        moves.pop_back();
    }
    if(colNo>=1 && m[rowNo][colNo-1]==1){
        moves.push_back('L');
        recursiveCall(rowNo,colNo-1,m,moves,output,n,doneMoves);
        moves.pop_back();
    }
    if(colNo<n-1 && m[rowNo][colNo+1]==1){
        moves.push_back('R');
        recursiveCall(rowNo,colNo+1,m,moves,output,n,doneMoves);
        moves.pop_back();
    }
    doneMoves.erase(doneMoves.find({rowNo,colNo}));
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> output;
    string moves;
    set<pair<int,int>> doneMoves;
    if (m[0][0] == 0)  return output;
    
    recursiveCall(0,0,m,moves,output,n,doneMoves);
    for(auto &it:output){
        cout<<it<<endl;
    }
    return output;
}

int main()
{
    vector<int> m1={1,0,0,0};
    vector<int> m2={1,1,0,1};
    vector<int> m3={1,1,0,0};
    vector<int> m4={0,1,1,1};
    vector<vector<int>> m;
    m.push_back(m1);
    m.push_back(m2);
    m.push_back(m3);
    m.push_back(m4);
    findPath(m,4);
    return 0;
}