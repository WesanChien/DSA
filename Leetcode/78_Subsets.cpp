#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) { // BT，每層把現有的 res 加 nums 進去 or not
        vector<vector<int>> res = {{}};

        for(int num : nums){
            int size = res.size();
            for(int i = 0; i < size; i++){
                vector<int> tmp = {};
                tmp.push_back(num);
                res.push_back(tmp);
            }
        }
        return res;
    }
};

class Solution2 {
public:
    vector<vector<int>> res;
    vector<int> subset;
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
private:
    void dfs(vector<int> nums, int i){
        if(i >= nums.size()){
            res.push_back(subset);
            return;
        }
        // Decision Tree 要這個數字 nums[i]
        subset.push_back(nums[i]);
        dfs(nums, i + 1);
        // Decision Tree 不加這個數字 nums[i]
        subset.pop_back();
        dfs(nums, i + 1;);
    }
}

int main(){
    vector<int> nums1 = {1, 2, 3}; // res 的順序是 {{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}}
    return 0;
}