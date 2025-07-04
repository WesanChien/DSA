#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string encode(vector<string>& strs) {
        string res = "";
        for(auto i:strs){
            res += to_string(i.size()) + ':' + i;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i < s.length()){
            int j = i;
            while(s[j] != ':') j++; // 找到delimeter s[j] = ':'
            int num = stoi(s.substr(i, j - i)); // s[i] ~ s[j - 1]是數字，不能只寫s[j - 1]因為有可能是十位數以上
            res.push_back(s.substr(j + 1, num)); // substr(start, length)
            i = j + 1 + num;
        }
        return res;
    }
};


int main(){
    Solution sol;
    vector<string> str1 = {"neet","code","love","you"}; /* encode into a single string s = "4:neet4:code4:love3:you", 
    even the string has ":" inside doesn't matter, cuz it'll be taken from the length number first */
    vector<string> str2 = {"we","say",":","yes"}; // 2:we3:say1::3:yes

    string encoded1 = sol.encode(str1);
    vector<string> decoded1 = sol.decode(encoded1);
    string encoded2 = sol.encode(str2);
    vector<string> decoded2 = sol.decode(encoded2);

    cout << encoded1 << endl;
    for(auto i:decoded1){
        cout << i << " ";
    }
    cout << endl;
    cout << encoded2 << endl;
    for(auto i:decoded2){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}