#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    string largestGoodInteger(string num) {
        string res = "";
        int n = num.size();

        for(int i = 0; i < n - 2; i++){
            if(num[i] == num[i + 1] && num[i] == num[i + 2]){
                if(res == ""){
                    res.append(3, num[i]);
                }
                else{
                    if(res[0] < num[i]){ // 字元不用轉int，因為ASCII也照順序排
                        res = "";
                        res.append(3, num[i]);
                    }
                }
            }
        }
        return res;
    }
};

class Solution2 {
public:
    string largestGoodInteger(string num) {
        char res = '\0';

        for (int i = 0; i < num.size() - 2; i++) {
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                res = max(res, num[i]);
            }
        }
        return res == '\0' ? "" : string(3, res);
    }
};

class Solution3 {
public:
    string largestGoodInteger(string s) {
         if (s.find("999") != string::npos) return "999"; // find() 找不到 substring 時，會回傳 string::npos
        if (s.find("888") != string::npos) return "888";
        if (s.find("777") != string::npos) return "777";
        if (s.find("666") != string::npos) return "666";
        if (s.find("555") != string::npos) return "555";
        if (s.find("444") != string::npos) return "444";
        if (s.find("333") != string::npos) return "333";
        if (s.find("222") != string::npos) return "222";
        if (s.find("111") != string::npos) return "111";
        if (s.find("000") != string::npos) return "000";
        return "";
    }
};

int main(){
    Solution3 sol;
    string num1 = "633317779";
    string num2 = "2300019";
    string num3 = "42352338";
    cout << sol.largestGoodInteger(num1) << endl;
    cout << sol.largestGoodInteger(num2) << endl;
    cout << sol.largestGoodInteger(num3) << endl;
}