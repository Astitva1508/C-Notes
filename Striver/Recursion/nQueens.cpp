#include <bits/stdc++.h>
using namespace std;

vector<char> possibleFillings(int rowNo,int colNo,vector<vector<char>> &board){
    unordered_set<char> tester;
    vector<char> possibleFills;
    for (int i=0;i<9;i++){
        if (board[rowNo][i] != '.') tester.insert(board[rowNo][i]);
        if (board[i][colNo] != '.') tester.insert(board[i][colNo]);
    }
    for (int i = 1; i <= 9; i++)
    {
        char x = i + 48;
        if(tester.find(x)==tester.end()) possibleFills.push_back(x);
    }
    return possibleFills;
}
void recursiveCall(int rowNo,vector<vector<char>> &board){
    if(rowNo==9) return;
    int i;
    for(i=0;i<9;i++){
        if (board[rowNo][i] == '.')
        {
            vector<char> possibleFills = possibleFillings(rowNo, i, board);
            if (possibleFills.empty()) return;
            for (auto it : possibleFills)
            {
                board[rowNo][i] = it;
                recursiveCall(rowNo, board);
            }
        }
    }if(i==8) recursiveCall(rowNo+1,board);
}

void solveSudoku(vector<vector<char>> &board){
    recursiveCall(0,board);
    for(auto &it :board){
        for (auto j:it)cout<<j<<" ";
        cout<<endl;
    }
}

int main(){
    vector<vector<char>> board;
    vector<char> board1 = {'5','3','.','.','7','.','.','.','.'};
    vector<char> board2 = {'6','.','.','1','9','5','.','.','.'};
    vector<char> board3 = {'.','9','8','.','.','.','.','6','.'};
    vector<char> board4 = {'8','.','.','.','6','.','.','.','3'};
    vector<char> board5 = {'4','.','.','8','.','3','.','.','1'};
    vector<char> board6 = {'7','.','.','.','2','.','.','.','6'};
    vector<char> board7 = {'.','6','.','.','.','.','2','8','.'};
    vector<char> board8 = {'.','.','.','4','1','9','.','.','5'};
    vector<char> board9 = {'.','.','.','.','8','.','.','7','9'};
    board.push_back(board1);
    board.push_back(board2);
    board.push_back(board3);
    board.push_back(board4);
    board.push_back(board5);
    board.push_back(board6);
    board.push_back(board7);
    board.push_back(board8);
    board.push_back(board9);
    solveSudoku(board);
}