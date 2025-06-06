#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
    }
};

class Solution2 { // 排序後兩邊夾起來找，排序要用pair把index也一起綁著動
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> tmp;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){ //不是for(int i:nums)
            tmp.push_back({nums[i], i});
        }

        sort(tmp.begin(), tmp.end());

        int i = 0, j = nums.size() - 1;
        while(i < j){
            if(tmp[i].first + tmp[j].first == target){
                ans.push_back(min(tmp[i].second, tmp[j].second));
                ans.push_back(max(tmp[i].second, tmp[j].second));
                return ans;
            }
            else if(tmp[i].first + tmp[j].first < target) i++;
            else j--;
        }
        return {};
    }
};

class Solution3 { // diff存起來，可O(n)直接找出兩個，事先用map把對應index存起來
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> tmp;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            tmp[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if(tmp.count(diff) && tmp[diff] != i){
                return {i, tmp[diff]};
            }
        }
    }
};

int main(){
    Solution2 sol;
    vector<int> nums1 = {3, 4, 5, 6};
    vector<int> nums2 = {4, 5, 6};
    vector<int> nums3 = {-1, -2, -3, -4, -5};
    vector<int> ans1 = sol.twoSum(nums1, 7);
    vector<int> ans2 = sol.twoSum(nums2, 10);
    vector<int> ans3 = sol.twoSum(nums3, -8);
    for(int i:ans1){
        cout << i << " ";
    }
    cout << endl;
    for(int i:ans2){
        cout << i << " ";
    }
    cout << endl;
    for(int i:ans3){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}