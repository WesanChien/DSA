#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans, index;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == key){
                index.push_back(i); // 把key值相同的index存起來
            }
        }

        int indexLength = index.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < indexLength; j++){
                if(abs(i - index[j]) <= k){
                    ans.push_back(i);
                    break; // 避免重複push
                }
            }
        }
        return ans;
    }
};

/* 
找出 nums[j] == key 距離 k 的所有 index i，滿足| i - j | <= k，所以 j-k <= i <= j+k，
但是j-k不能小於0，j+k不能大於n-1，所以是 max(0, j-k) <= i <= min(n-1, j+k)，
在 j 的左右距離k個index，有可能會重複抓，所以用 r 去從還沒抓過的最小開始刷新
*/

class Solution2 { 
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int r = 0;
        int n = nums.size();
        for (int j = 0; j < n; j++) {
            if (nums[j] == key) {
                int l = max(r, j - k); // 寫max(0, j - k)會重複抓
                r = min(n - 1, j + k) + 1; // 更新下一個未處理過的
                for (int i = l; i < r; i++) {
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution2 sol;
    vector<int> nums1 = {3, 4, 9, 1, 3, 9, 5};
    vector<int> nums2 = {2, 2, 2, 2, 2};
    vector<int> ans1 = sol.findKDistantIndices(nums1, 9, 1);
    vector<int> ans2 = sol.findKDistantIndices(nums2, 2, 2);

    for(int i:ans1){cout << i << " ";}
    cout << endl;
    for(int i:ans2){cout << i << " ";}
    cout << endl;

    return 0;
}