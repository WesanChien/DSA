#include <iostream>
#include <stack>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution1 { // O(logn)
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[l] <= nums[r]) return nums[l];
            else if(nums[l] <= nums[mid] && nums[mid] >= nums[r]){
                l = mid + 1;
            }
            else if(nums[l] >= nums[mid] && nums[mid] <= nums[r]){
                r = mid;
            }
        }
    }
};

class Solution2 { // O(logn) 精簡版
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < nums[r]) { // 右邊都是變大的，右半邊直接砍掉
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l];
    }
};

int main(){
    Solution2 sol;
    vector<int> nums1 = {3, 4, 5, 6, 1, 2}; // l=3, mid=5, r=2
    vector<int> nums2 = {6, 7, 0, 1, 2, 3, 4, 5}; // l=6, mid=1, r=5
    vector<int> nums3 = {4, 5, 6, 7}; // l=4, mid=5, r=7
    cout << sol.findMin(nums1) << endl;
    cout << sol.findMin(nums2) << endl;
    cout << sol.findMin(nums3) << endl;
    return 0;
}