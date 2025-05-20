#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums[0] + nums[1] <= nums[2]) return "none";
        if(nums[0]== nums[2]) return "equilateral";
        if(nums[0] == nums[1] || nums[1] == nums[2]) return "isosceles";
        else return "scalene";
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {3, 4, 5};
    cout << solution.triangleType(nums1) << endl; 
    vector<int> nums2 = {3, 3, 3};
    cout << solution.triangleType(nums2) << endl; 
    vector<int> nums3 = {5, 5, 2};
    cout << solution.triangleType(nums3) << endl; 
    vector<int> nums4 = {1, 1, 2};
    cout << solution.triangleType(nums4) << endl; 
    
    return 0;
}