#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> ans = matrix;
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                if(ans[i][j] == 0){
                    for(int k = 0; k < ans.size(); k++){
                        matrix[k][j] = 0;
                    }
                    for(int l = 0; l < ans[i].size(); l++){
                        matrix[i][l] = 0;
                    }
                }
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class Solution2{
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> rowZero(m, false);
        vector<bool> colZero(n, false);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rowZero[i] = true;
                    colZero[j] = true;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rowZero[i] || colZero[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (auto& row : matrix) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    Solution2 solution;
    vector<vector<int>> nums1 = {{1,1,1}, {1,0,1}, {1,1,1}};
    vector<vector<int>> nums2 = {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};
    solution.setZeroes(nums1);
    solution.setZeroes(nums2);
    return 0;
}