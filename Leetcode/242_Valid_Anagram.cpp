#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution1 {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

class Solution2 {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> count(26, 0);
        for(int i = 0; i < s.length(); i++){
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for(int i:count){
            if(i != 0) return false;
        }
        return true;
    }
};

class Solution3 {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, int> sCount; // map['a'] == 97, map['b'] == 98, etc.  
        unordered_map<char, int> tCount;
        for(int i = 0; i < s.length(); i++){
            sCount[s[i]]++;
            tCount[t[i]]++;
        }
        return sCount == tCount;
    }
};

int main(){
    Solution2 sol;
    string s = "racecar", t = "carrace";
    cout << sol.isAnagram(s, t) << endl;
    return 0;
}
