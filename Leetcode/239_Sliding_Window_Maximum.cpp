#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution1 { // Brutal-Force
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res; // size = n - k + 1

        for(int i = 0; i < n - k + 1; i++){
            int maxi = nums[i];
            for(int j = i; j < i + k; j++){
                maxi = max(maxi, nums[j]);
            }
            res.push_back(maxi);
        }

        return res;
    }
};

class Solution2 { // Max-Heap
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res; // size = n - k + 1
        priority_queue<pair<int, int>> maxHeap;
        
        for(int i = 0; i < n; i++){
            maxHeap.push({nums[i], i});
            if(i - k + 1 >= 0){ // 因為 window 範圍是 [i-k+1, i]
                while (maxHeap.top().second < i - k + 1) { // 可能有非當前window元素在heap內
                    maxHeap.pop();
                }
                res.push_back(maxHeap.top().first);
            }
        }
        return res;
    }
};

class Solution3 { // Monotonic Decreasing Queue(Deque)，q[0] 為最大值，遞減排序
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = 0;
        vector<int> res(n - k + 1);
        deque<int> q; // 這裡純放 index

        while (r < n) { // no out-of-bound
            while (!q.empty() && nums[q.back()] < nums[r]) { // pop smaller value
                q.pop_back();
            }
            q.push_back(r);
            // remove 不在 window 範圍的 q[0]
            if (l > q.front()) {
                q.pop_front();
            }

            if ((r + 1) >= k) {
                res[l] = nums[q.front()];
                l++;
            }
            r++;
        }

        return res;
    }
};

int main() {
    Solution3 sol;
    vector<int> nums1 = {1, 2, 1, 0, 4, 2, 6}; // 2, 2, 4, 4, 6
    vector<int> nums2 = {1, 2, 1, 0, 4, 2, 6}; // 2, 2, 1, 4, 4, 6

    for(int i : sol.maxSlidingWindow(nums1, 3)){
        cout << i << " ";
    }
    cout << endl;
    for(int i : sol.maxSlidingWindow(nums2, 2)){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}