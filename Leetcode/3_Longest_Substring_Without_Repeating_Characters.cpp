#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            unordered_set<char> myUnordered_set;
            for(int j = i; j < s.size(); j++){
                // if(myUnordered_set.count(s[j]) != 0) break;
                if(myUnordered_set.find(s[j]) != myUnordered_set.end()){ //有找到，==set.end()就是沒找到
                    break;
                }
                else{
                    myUnordered_set.insert(s[j]);
                }
            }
            res = max(res, (int)myUnordered_set.size());
        }
        return res;
    }
};

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, res = 0;
        unordered_set<char> myUnordered_set;

        for(int r = 0; r < s.size(); r++){
            while(myUnordered_set.find(s[r]) != myUnordered_set.end()){
                myUnordered_set.erase(s[l]);
                l++;
            } // set內從左邊刪除到重複出現的那個char為止，刪完可以加入新那個char，再繼續找
            myUnordered_set.insert(s[r]);
            res = max(res, r - l + 1); // r-l+1 是當前的set size
        }
        return res;
    }
};

int main(){
    Solution2 sol;
    string str1 = "abcabbbd";
    string str2 = "aab";
    string str3 = "pwwkew";
    string str4 = "dvadf";
    cout << sol.lengthOfLongestSubstring(str1) << endl;
    cout << sol.lengthOfLongestSubstring(str2) << endl;
    cout << sol.lengthOfLongestSubstring(str3) << endl;
    cout << sol.lengthOfLongestSubstring(str4) << endl;
    return 0;
}