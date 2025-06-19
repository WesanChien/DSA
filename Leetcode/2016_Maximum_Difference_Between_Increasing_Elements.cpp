#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

class Solution1 {
public:
    int maximumDifference(vector<int>& nums) {
        int tmpMax = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                // if(nums[j] - nums[i] > max){
                //     max = nums[j] - nums[i];
                // }
                tmpMax = max(tmpMax, nums[j] - nums[i]);
            }
        }
        if(tmpMax == 0) return -1;
        return tmpMax;
    }
};

class Solution2 {
public:
    int maximumDifference(vector<int>& nums) {
        int tmpMax = -1, premin = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > premin) {
                tmpMax = max(tmpMax, nums[i] - premin);
            } else {
                premin = nums[i]; // 更新premin去往後找最大差，但是最大差前面的已經存好了
            }
        }
        return tmpMax;
    }
};
int main(){
    Solution2 sol;
    vector<int> case1 = {7, 1, 5, 4};
    vector<int> case2 = {9, 4, 3, 2};
    vector<int> case3 = {6, 42, 5 ,9};
    int ans1 = sol.maximumDifference(case1);
    int ans2 = sol.maximumDifference(case2);
    int ans3 = sol.maximumDifference(case3);
    cout << ans1 << endl;
    cout << ans2 << endl;
    cout << ans3 << endl;
    return 0;
}