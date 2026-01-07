#include <iostream>
#include <stack>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int mid = (l + r) / 2;

        while(l <= r){
            mid = (l + r) / 2;

            // if(nums[l] < nums[r]){ // 正常小到大排序
            //     if(target > nums[mid]) l = mid + 1;
            //     else if(target < nums[mid]) r = mid - 1;
            //     else if(target == nums[mid]) return mid;
            //     else return -1;
            // }

            if(target == nums[mid]) return mid;
            else if(nums[l] > nums[mid]){ // 右半排序正常
                if(target > nums[mid] && target <= nums[r]) l = mid + 1; // 左半丟掉，不能l=mid來丟，因為只剩2個value時，會不變，導致無限loop
                else r = mid - 1; // 右半丟掉
            }
            else{ // 左半排序正常
                if(target >= nums[l] && target < nums[mid]) r = mid - 1; // 右半丟掉
                else l = mid + 1; // 左半丟掉
            }
        }
        return -1;
    }
};

int main(){
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 4, 5, 6}; // l=1, mid=3, r=6
    vector<int> nums2 = {7, 8, 3, 4, 5, 6}; // l=7, mid=3, r=6
    vector<int> nums3 = {3, 4, 5, 6, 1, 2}; // l=3, mid=5, r=2
    cout << sol.search(nums1, 1) << endl; // 0
    cout << sol.search(nums2, 5) << endl; // 4
    cout << sol.search(nums3, 2) << endl; // 5
    cout << sol.search(nums2, 1) << endl; // -1
    return 0;
}