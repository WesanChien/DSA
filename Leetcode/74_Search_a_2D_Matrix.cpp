#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(target == matrix[i][j]) return true;
            }
        }
        return false;
    }
};

class Solution2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int topRow = 0, botRow = m - 1;
        
        while(topRow <= botRow){
            int midRow = (topRow + botRow) / 2;
            if(target > matrix[midRow][n - 1]){
                topRow = midRow + 1;
            }
            else if(target < matrix[midRow][0]){
                botRow = midRow - 1;  
            }
            else break; // 代表 target 在此 midRow 了
        }

        int midRow = (topRow + botRow) / 2; 
        int l = 0, r = n -1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(target > matrix[midRow][mid]){
                l = mid + 1;
            }
            else if(target < matrix[midRow][mid]){
                r = mid - 1;
            }
            else return true;
        }
        return false;
    }
};

int main(){
    Solution2 sol;
    vector<vector<int>> matrix1 = {{1, 2, 4, 8}, {10, 11, 12, 13}, {14, 20, 30, 40}};
    cout << sol.searchMatrix(matrix1, 14) << endl;
    cout << sol.searchMatrix(matrix1, 15) << endl;
    cout << sol.searchMatrix(matrix1, 10) << endl;
    return 0;
}