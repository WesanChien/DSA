#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution1 {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result;
        int currentGroup = -1;
        for(int i = 0; i < groups.size(); i++){
            if(groups[i] != currentGroup){ // 也可以 if(groups[i] != groups[i - 1] || i == 0)
                result.push_back(words[i]);
                currentGroup = groups[i];
            }
        }
        return result;
    }
};

class Solution2 { // DP
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1); // dp[i] 為Longest Valid Subsequence 以 words[i]當結尾
        vector<int> prev(n, -1); // Longest Valid Subsequence 的前一個 index
        int maxLen = 1, endIndex = 0; // 預設必定有index = 0 的元素，maxLen = 1

        for (int i = 1; i < n; i++) {
            int bestLen = 1;
            int bestPrev = -1;
            for (int j = i - 1; j >= 0; j--) {
                if (groups[i] != groups[j] && dp[j] + 1 > bestLen) {
                    bestLen = dp[j] + 1;
                    bestPrev = j; // 紀錄目前是 0 or 1 結尾
                }
            } // 考慮前 i 個能組出的解，再往後考慮
            dp[i] = bestLen; // 前 i 個能組出的最大長度
            prev[i] = bestPrev; // 記錄前 i 個總共是怎麼走過來的
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                endIndex = i;
            }
        }
        vector<string> res;
        for (int i = endIndex; i != -1; i = prev[i]) {
            res.emplace_back(words[i]); 
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution2 solution;
    vector<string> words1 = {"e", "a", "b"};
    vector<int> groups1 = {0, 0, 1};
    vector<string> result1 = solution.getLongestSubsequence(words1, groups1);
    for(string& word : result1) {
        cout << word << " ";
    }
    cout << endl;
    vector<string> words2 = {"a", "b", "c", "d"};
    vector<int> groups2 = {1, 0, 1, 1};
    vector<string> result2 = solution.getLongestSubsequence(words2, groups2);
    for(auto& word : result2) {
        cout << word << " ";
    }
    return 0;
}