#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution1 { // 用 set 去重，O(n^2logn)
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> tmp;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(nums[i] > 0) break; // 沒有解
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){ // 兩邊夾起來O(n)
                    tmp.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        set<vector<int>> uniqueSet(tmp.begin(), tmp.end()); // 用set做去重，unordered_set會誤以為不同[1, 0, 1]跟[1, 1, 0]
        vector<vector<int>> ans(uniqueSet.begin(), uniqueSet.end());
        return ans;
    }
};

class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue; // 如果nums[i]跟nums[i - 1]一樣，要跳過
            if(nums[i] > 0) break;
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){ // 兩邊夾起來O(n)
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j - 1]){ // 找到答案後，代表3個值相同，現在i固定，j或k要檢查(跟更新後的值相比，一樣就再跳)，就不會抓到相同的值push到ans
                        j++;
                    }
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution2 sol;
    vector<int> numbers1 = {-1, 0, 1, 2, -1, -4};
    vector<int> numbers2 = {0, 1, 1};
    vector<int> numbers3 = {0, 0, 0, 0};
    vector<int> numbers4 = {1, -1, -1, 0};
    vector<vector<int>> ans1 = sol.threeSum(numbers1);
    vector<vector<int>> ans2 = sol.threeSum(numbers2);
    vector<vector<int>> ans3 = sol.threeSum(numbers3);
    vector<vector<int>> ans4 = sol.threeSum(numbers4);
    for(int i = 0; i < ans1.size(); i++){
        for(int j = 0; j < ans1[i].size(); j++){
            cout << ans1[i][j] << " ";
        }
    }
    cout << endl;
    for(int i = 0; i < ans2.size(); i++){
        for(int j = 0; j < ans2[i].size(); j++){
            cout << ans2[i][j] << " ";
        }
    }
    cout << endl;
    for(int i = 0; i < ans3.size(); i++){
        for(int j = 0; j < ans3[i].size(); j++){
            cout << ans3[i][j] << " ";
        }
    }
    cout << endl;
    for(int i = 0; i < ans4.size(); i++){
        for(int j = 0; j < ans4[i].size(); j++){
            cout << ans4[i][j] << " ";
        }
    }
    cout << endl;
    return 0;
}