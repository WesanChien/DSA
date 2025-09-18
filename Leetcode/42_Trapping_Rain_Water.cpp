#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    int trap(vector<int>& height) { // 算出每個h[i]能裝多少，min(l, r) - h[i]
        int res = 0;
        int n = height.size();
        
        for(int i = 0; i < n; i++){
            int leftMax = height[i];
            int rightMax = height[i];

            for(int j = 0; j < i; j++){
                leftMax = max(leftMax, height[j]);
            }
            for(int j = i + 1; j < n; j++){
                rightMax = max(rightMax, height[j]);
            }

            res += min(leftMax, rightMax) - height[i]; // max柱子都從height[i]開始找，至少有height[i]高度，所以不會加到負值
        }

        return res;
    }
};

class Solution2 {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        int l = 0, r = n - 1;
        int leftMax = height[l], rightMax = height[r];

       
        while(l < r){
            if(leftMax <= rightMax){
                l++; // 先 shift，因為這樣才是最小 leftMax 跟當前 height[l] 比
                leftMax = max(leftMax, height[l]); // 先更新 leftMax ，避免leftMax - height[l] 變負數
                res += leftMax - height[l];
            }
            else{
                r--;
                rightMax = max(rightMax, height[r]);
                res += rightMax - height[r];
            }
        }
        return res;
    }
};

int main(){
    Solution2 sol;

    vector<int> numbers1 = {0, 2, 0, 3, 1, 0, 1, 3, 2, 1};
    vector<int> numbers2 = {0, 3, 1, 0, 1, 3};
    vector<int> numbers3 = {1, 0, 2, 0, 3};
    cout << sol.trap(numbers1) << endl;
    cout << sol.trap(numbers2) << endl;
    cout << sol.trap(numbers3) << endl;
    
    return 0;
}