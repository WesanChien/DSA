#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution1 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> mySet;
        int n = 9;
        // Check row valid
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '.') continue;
                if(mySet.count(board[i][j])) return false;
                mySet.insert(board[i][j]);
            }
            mySet.clear();
        }
        mySet.clear();
        // Check column valid
        for(int j = 0; j < n; j++){
            for(int i = 0; i < n; i++){
                if(board[i][j] == '.') continue;
                if(mySet.count(board[i][j])) return false;
                mySet.insert(board[i][j]);
            }
            mySet.clear();
        }
        // Check 3x3 valid
        for(int i = 0; i < n; i += 3){
            for(int j = 0; j < n; j += 3 ){
                // check 3x3 inside
                for(int k = 0; k < 3; k++){
                    for(int l = 0; l < 3; l++){
                        if(board[k + i][l + j] == '.') continue;
                        if(mySet.count(board[k + i][l + j])) return false;
                        mySet.insert(board[k + i][l + j]);
                    }
                }
                mySet.clear();
            }
        }
        return true;
    }
};


int main(){
    vector<vector<char>> board1 = {{'1','2','.','.','3','.','.','.','.'},
 {'4','.','.','5','.','.','.','.','.'},
 {'.','9','8','.','.','.','.','.','3'},
 {'5','.','.','.','6','.','.','.','4'},
 {'.','.','.','8','.','3','.','.','5'},
 {'7','.','.','.','2','.','.','.','6'},
 {'.','.','.','.','.','.','2','.','.'},
 {'.','.','.','4','1','9','.','.','8'},
 {'.','.','.','.','8','.','.','7','9'}};
    vector<vector<char>> board2 = 
    {{'1','2','.','.','3','.','.','.','.'},
 {'4','.','.','5','.','.','.','.','.'},
 {'.','9','1','.','.','.','.','.','3'},
 {'5','.','.','.','6','.','.','.','4'},
 {'.','.','.','8','.','3','.','.','5'},
 {'7','.','.','.','2','.','.','.','6'},
 {'.','.','.','.','.','.','2','.','.'},
 {'.','.','.','4','1','9','.','.','8'},
 {'.','.','.','.','8','.','.','7','9'}};
    Solution1 sol;
    cout << sol.isValidSudoku(board1) << endl;
    cout << sol.isValidSudoku(board2) << endl;
    return 0;
}