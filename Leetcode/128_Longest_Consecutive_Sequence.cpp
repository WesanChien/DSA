#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

class Solution1 { // O(nlogn)
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 1, curLen = 1, n = nums.size();
        set<int> mySet; // RB tree find needs O(logn)
        if(nums.empty()) return 0;
        for(int i:nums){
            mySet.insert(i);
        }
        vector<int> myVec(mySet.begin(), mySet.end());
        for(int i = 1; i < myVec.size(); i++){
            if(myVec[i] == myVec[i - 1] + 1){ // 用myVec[i]+1 == myVec[i+1]會out of bounds 
                curLen++;
            }
            else{
                maxLen = max(curLen, maxLen);
                curLen = 1;
            }
        }
        maxLen = max(curLen, maxLen);
        return maxLen;
    }
};

class Solution2 { // O(n)
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int curLen = 0, maxLen = 0;
        unordered_set<int> mySet; // hash table find just O(1)
        for(int i:nums){
            mySet.insert(i);
        }
        for(int i:mySet){ 
            if(mySet.count(i - 1) == 0){ // 找看看它是不是頭
                curLen = 1; // 是頭的話就至少有curLen長度1
                while(mySet.count(i + curLen)){ // 用迴圈繼續找他的下家有多長
                    curLen++;   
                }
                maxLen = max(curLen, maxLen);
            }
        }
        return maxLen;
    }
};


int main(){
    Solution2 sol;
    vector<int> nums1 = {};
    vector<int> nums2 = {0, 3, 2, 5, 4, 6, 1, 1};
    vector<int> nums3 = {9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6}; // myVec = {-1, 0, 1, 3, 4, 5, 6, 7, 8, 9}
    cout << sol.longestConsecutive(nums1) << endl;
    cout << sol.longestConsecutive(nums2) << endl;
    cout << sol.longestConsecutive(nums3) << endl;
    return 0;
}