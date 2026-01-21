#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution1 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& Strs) {
        int n = Strs.size();
        vector<vector<string>> ans;
        vector<string> sortedStrs = Strs;
        for(int i = 0; i < n; i++){
            sort(sortedStrs[i].begin(), sortedStrs[i].end());
        }
        unordered_map<string, vector<string>> mp; // unordered_map<string, int> mp; 可寫mp["cat"] += 1; 這樣act, tac都會加mp["cat"]
        for(int i = 0; i < n; i++){
            mp[sortedStrs[i]].push_back(Strs[i]);
        }
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& Strs) {
    }
};

int main(){
    Solution2 sol;
    vector<string> str1 ={"act","pots","tops","cat","stop","hat"};
    vector<string> str2 ={"x"};
    vector<string> str3 ={""};
    vector<vector<string>> ans1 = sol.groupAnagrams(str1);
    vector<vector<string>> ans2 = sol.groupAnagrams(str2);
    vector<vector<string>> ans3 = sol.groupAnagrams(str3);
    for(auto group : ans1){
        for(auto word : group){
            cout << word;
        }
        cout << " ";
    }
    cout << endl;
    for(auto group : ans2){
        for(auto word : group){
            cout << word;
        }
        cout << " ";
    }
    cout << endl;
    for(auto group : ans3){
        for(auto word : group){
            cout << word;
        }
        cout << " ";
    }
    cout << endl;
    return 0;
}