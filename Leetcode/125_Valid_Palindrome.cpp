#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    bool isPalindrome(string s) {
        string str;
        int n = s.size();
        for(int i = 0; i < n; i++){ // 去除非alphanumeric跟大小寫
            if(isalnum(s[i])){ // is AlphaNumeric : isalnum(' ' or '!') will return false
                str.push_back(tolower(s[i]));
            }
        }
        string revStr = str;
        reverse(revStr.begin(), revStr.end());
        return str == revStr;
    }
};

class Solution2 {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r){
            while(l < r && !isalnum(s[l])){ //空格、符號跳過
                l++;
            }
            while(l < r && !isalnum(s[r])){ //空格、符號跳過
                r--;
            }
            if(tolower(s[l]) == tolower(s[r])){
                l++;
                r--;
            }
            else return false;
        }
        return true;
    }
};


int main(){
    Solution2 sol;
    string s1 = "Was it a car or a cat I saw?";
    string s2 = "tab a cat";
    cout << sol.isPalindrome(s1) << endl;
    cout << sol.isPalindrome(s2) << endl;
    return 0;
}