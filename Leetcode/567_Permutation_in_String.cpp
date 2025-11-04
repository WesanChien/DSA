#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
class Solution1 {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        sort(s1.begin(), s1.end());
        for(int i = 0; i < n; i++){
            string s3 = s2.substr(i, m); // 從 i 開始長度為 m 的子字串
            sort(s3.begin(), s3.end());
            if(s1 == s3) return true;
        }
        return false;
    }
};

class Solution2 { // 兩張map，去比對是不是都是一樣的字母，26個map[字母]會完全一樣
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> count1;
        for (char c : s1) {
            count1[c]++;
        }

        int n = count1.size(); // 跟 int n = s1.size() 一樣意思
        for (int i = 0; i < s2.length(); i++) {
            unordered_map<char, int> count2;
            int cur = 0;
            for (int j = i; j < s2.length(); j++) {
                count2[s2[j]]++;

                if (count1[s2[j]] < count2[s2[j]]) {
                    break; // map有出現不一樣就跳過了
                }

                if (count1[s2[j]] == count2[s2[j]]) {
                    cur++;
                }

                if (cur == n) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution2 sol;
    string str1 = "abc";
    string str2 = "lecabee";
    string str3 = "lecaabee";
    cout << sol.checkInclusion(str1, str2) << endl;
    cout << sol.checkInclusion(str1, str3) << endl;
    return 0;
}