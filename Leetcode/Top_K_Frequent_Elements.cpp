#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#define pii pair<int, int>

using namespace std;

// bool cmpSec(const pair<int, int>& a, const pair<int, int>& b);

class Solution1 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        //vector<pair<int, int>> tmp(mp.begin(), mp.end());
        //sort(tmp.begin(), tmp.end(), cmpSec);

        /*轉vector<pair>>才能對value(second)做排序*/
        vector<pair<int, int>> tmp;
        for(auto i:mp){
            tmp.push_back({i.second, i.first}); // 因為sort是比較first，所以轉換時顛倒過來
        }
        sort(tmp.rbegin(), tmp.rend()); // 由大到小
        
        for(int i = 0; i < k; i++){
            ans.push_back(tmp[i].second);
        }
        return ans;
    }
};

// bool cmpSec(const pair<int, int>& a, const pair<int, int>& b){
//     return a.second > b.second;
// }

class Solution2 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        priority_queue<pii> maxHeap; // minHeap寫priority_queue<pii, vector<pii>, greater<pii>> minHeap
        for(auto i:mp){
            maxHeap.push({i.second, i.first});
        }
        for(int i = 0; i < k; i++){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};

int main(){
    Solution2 sol;
    vector<int> nums1 = {1, 2, 2, 3, 3, 3};
    vector<int> nums2 = {7, 7};
    vector<int> nums3 = {1, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 7};
    vector<int> ans1 = sol.topKFrequent(nums1, 2);
    vector<int> ans2 = sol.topKFrequent(nums2, 1);
    vector<int> ans3 = sol.topKFrequent(nums3, 3);
    for(int i:ans1){
        cout << i << " ";
    }
    cout << endl;
    for(int i:ans2){
        cout << i << " ";
    }
    cout << endl;
    for(int i:ans3){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}