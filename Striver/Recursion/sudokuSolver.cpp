#include <bits/stdc++.h>
using namespace std;

bool isSafe(int rowNo, int colNo, vector<vector<char>> &board,char c)
{
    for(int i=0;i<9;i++){
        if(board[rowNo][i] == c) return false;
        if(board[i][colNo] == c) return false;
    }
    int start = (rowNo / 3) * 3;
    int end = (colNo / 3) * 3;
    for(int i=start;i<start+3;i++){
        for(int j=end;j<end+3;j++){
            if(board[i][j] == c) return false;
        }
    }    
    return true;
}
bool recursiveCall(vector<vector<char>> &board)
{
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j] == '.'){
                for(char c='1';c<='9';c++){
                    if(isSafe(i,j,board,c)){
                        board[i][j] = c ;
                        if (recursiveCall(board)) return true ;
                        board[i][j]='.' ;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    recursiveCall(board);
    for (auto &it :board){
        for (auto j:it){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    vector<vector<char>> board;
    vector<char> board1 = {'5', '3', '.', '.', '7', '.', '.', '.', '.'};
    vector<char> board2 = {'6', '.', '.', '1', '9', '5', '.', '.', '.'};
    vector<char> board3 = {'.', '9', '8', '.', '.', '.', '.', '6', '.'};
    vector<char> board4 = {'8', '.', '.', '.', '6', '.', '.', '.', '3'};
    vector<char> board5 = {'4', '.', '.', '8', '.', '3', '.', '.', '1'};
    vector<char> board6 = {'7', '.', '.', '.', '2', '.', '.', '.', '6'};
    vector<char> board7 = {'.', '6', '.', '.', '.', '.', '2', '8', '.'};
    vector<char> board8 = {'.', '.', '.', '4', '1', '9', '.', '.', '5'};
    vector<char> board9 = {'.', '.', '.', '.', '8', '.', '.', '7', '9'};
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