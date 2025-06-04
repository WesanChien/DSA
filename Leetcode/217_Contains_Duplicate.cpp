#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){ // j = i + 1也可
                if(i == j) continue;
                if(nums[i] == nums[j]){
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution2 {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == nums[i + 1]) return true;
        }
        return false;
    }
};

class Solution3 {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int i : nums){
            if(seen.count(i)) return true; //unordered_set.count()有重複data會return true
            seen.insert(i);
        }
        return false;
    }
};

class Solution4{
public:
    bool hasDuplicate(vector<int>& nums) {
        return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
    }
};

int main(){
    Solution4 sol;
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {1, 2, 3, 3};
    cout << sol.hasDuplicate(nums1) << endl;
    cout << sol.hasDuplicate(nums2) << endl;
}