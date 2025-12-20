#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution { 
public:
    string minWindow(string s, string t) {
        string res = "";
        int resLen =  INT_MAX;
        unordered_map<char, int> countT;

        for(char c : t){
            countT[c]++;
        }
        // 跑所有 s 的 substring，確認 CountT[j] <= CountS[j] 對任意 j 都成立
        for(int i = 0; i < (int)s.length(); i++){
            unordered_map<char, int> countS;
            for(int j = i; j < (int)s.length(); j++){
                countS[s[j]]++;

                bool ok = true; // 用 bool ok 確認符合 CountT[j] <= CountS[j]
                for (auto [c, cnt] : countT) { // 遍佈整個 countT
                    if (countS[c] < cnt) {
                        ok = false;
                        break;
                    }
                }

                if (ok && (j - i + 1) < resLen) { // 長度較短就更新
                    resLen = j - i + 1;
                    res = s.substr(i, resLen);
                }
            }
        }
        if(resLen == INT_MAX) return "";
        return res;
    }
};

int main() {
    Solution sol;
    string s1 = "OUZODYXAZV", s2 = "XYZ", s3 = "XY", s4 = "XYZZ", s5 = "OUZODYXAZV";

    cout << sol.minWindow(s1, s2) << endl; // "YXAZ"
    cout << sol.minWindow(s2, s2) << endl; // "XYZ"
    cout << sol.minWindow(s3, s2) << endl; // ""
    cout << sol.minWindow(s5, s4) << endl; // "ZODYXAZ"

    return 0;
}