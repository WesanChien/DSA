#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution1 {
public:
    int binary_search(int l, int r, vector<int>& nums, int target){
        if(l > r) return -1;
        int mid = (l + r) / 2;

        if(nums[mid] == target) return mid;
        return ((nums[mid] > target) ? binary_search(l, mid - 1, nums, target) : binary_search(mid + 1, r, nums, target));
    }
    int search(vector<int>& nums, int target) {
        return binary_search(0, nums.size() - 1, nums, target);
    }
};


class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r){
        int mid = (l + r) / 2;
            if(target > nums[mid]){
                l = mid + 1;
                mid = (l + r) / 2;
            }
            else if(target < nums[mid]){
                r = mid - 1;
                mid = (l + r) / 2;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};


int main(){
    Solution1 sol;
    vector<int> nums1 = {-1, 0, 2, 4, 6, 8}; // sorted arr
    cout << sol.search(nums1, 3) << endl; // -1
    cout << sol.search(nums1, 4) << endl; // 3
    return 0;
}