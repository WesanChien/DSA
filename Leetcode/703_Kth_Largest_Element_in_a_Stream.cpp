#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class KthLargest1 {
private:
    int k;
    vector<int> nums;

public:
    KthLargest1(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums;
    }
    
    int add(int val) {
        nums.push_back(val);
        sort(nums.begin(), nums.end());

        return nums[nums.size() - k];
    }
};

class KthLargest2 {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    KthLargest2(int k, vector<int>& nums) {
        this->k = k;
        for(int i : nums) {
            minHeap.push(i);
            if(minHeap.size() > k) minHeap.pop();
        }
    }

    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};

int main(){
    vector<int> nums1 = {1, 2, 3, 3};
    KthLargest1 kthLargest(3, nums1);
    kthLargest.add(3);   // return 3
    kthLargest.add(5);   // return 3
    kthLargest.add(6);   // return 3
    kthLargest.add(7);   // return 5
    kthLargest.add(8);   // return 6
    return 0;
}