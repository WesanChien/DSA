#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution1 { // O(n^2)
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size(), k = 0;
        
        for(int i = 0; i < n; i++){
            int tmp = 1;
            for(int j = 0; j < n; j++){
                if(k == j) continue;
                tmp *= nums[j];   
            }
            k++;
            ans.push_back(tmp);
        }
        return ans;
    }
};

class Solution2 { //分成無0，有一0，超過一0，可O(n)
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int tmp = 1;
        /*超過一0*/
        unordered_map<int, int> mp;
        for(int i:nums){
            mp[i]++;
        }
        if(mp[0] > 1) return ans;
        /*有一0*/
        else if(mp[0] == 1){
            for(int i = 0; i < n; i++){
                if(nums[i] != 0) tmp *= nums[i]; 
            }
            for(int i = 0; i < n; i++){
                if(nums[i] == 0) ans[i] = tmp;
            }
        }
        /*無0*/
        else{
            for(int i = 0; i < n; i++){
                if(nums[i] != 0) tmp *= nums[i]; 
            }
            for(int i = 0; i < n; i++){
                    ans[i] = (tmp /= nums[i]);
                    tmp *= nums[i];
            }
        }
        return ans;
    }
};

class Solution3 { // ans[n] = prefix[n-1] * suffix[n+1]
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n), suffix(n), ans(n);

        prefix[0] = nums[0];
        suffix[n - 1] = nums[n - 1];

        for(int i = 1; i < n; i++){
            prefix[i] = nums[i] * prefix[i - 1];
        }
        for(int i = n - 2; i >= 0; i--){
            suffix[i] = nums[i] * suffix[i + 1];
        }

        for(int i = 1; i < n - 1; i++){
            ans[i] = prefix[i - 1] * suffix[i + 1];
        }
        ans[0] = 1 * suffix[1];
        ans[n - 1] = prefix[n - 2] * 1;

        return ans;
    }
};

int main(){
    Solution3 sol;
    vector<int> nums1 = {1, 2, 4, 6};
    vector<int> nums2 = {-1, 0, 1, 2, 3};
    vector<int> nums3 = {-1, 0, 0, 2, 3};
    vector<int> ans1 = sol.productExceptSelf(nums1);
    vector<int> ans2 = sol.productExceptSelf(nums2);
    vector<int> ans3 = sol.productExceptSelf(nums3);
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