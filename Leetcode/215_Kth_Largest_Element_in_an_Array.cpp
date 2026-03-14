#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k){
        int res;
        priority_queue<int> maxHeap;

        for(int i : nums) maxHeap.push(i);
        for(int i = k; i > 0; i--){
            res = maxHeap.top();
            maxHeap.pop();
        }

        return res;
    }
};

int main(){
    return 0;
}