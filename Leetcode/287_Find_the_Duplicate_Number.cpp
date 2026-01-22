#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution1 { // O(n) time and space
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> mySet;
        for(auto i : nums){
            if(mySet.find(i) != mySet.end()){
                return i;
            }
            mySet.insert(i);
        }
    }
};

class Solution2 { // O(n) time, O(1) space, but modified array
public:
    int findDuplicate(vector<int>& nums) { // array 內的 value 當作指到的 index，所以必定會重複改該 index 為負的
        for (int i : nums) {
            int index = abs(i) - 1;
            if (nums[index] < 0) {
                return abs(i);
            }
            nums[index] *= -1;
        }
        return -1;
    }
};

int main(){
    vector<int> nums1 = {2, 1, 4, 3, 3};
    return 0;
}