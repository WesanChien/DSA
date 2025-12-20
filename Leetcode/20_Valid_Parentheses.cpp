#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if(n % 2 != 0) return false;
        stack<char> myStack;
        for(char c : s){
            if(c == '(' || c == '{' || c == '[') myStack.push(c);
            else{
                if(myStack.empty()) return false;
                char open = myStack.top();
                if(c == ')' && open != '(') return false;
                else if(c == ']' && open != '[') return false;
                else if(c == '}' && open != '{') return false;
                else myStack.pop();
            }
        }
        // if(myStack.empty()){
        //     return true;
        // }
        // else return false; // 不能漏掉這行，Runtime Error，有可能沒有 return value
        return myStack.empty();
    }
};


int main(){
    Solution sol;
    string str1 = "[]";
    string str2 = "({[]})";
    string str3 = "[(])";
    cout << sol.isValid(str1) << endl;
    cout << sol.isValid(str2) << endl;
    cout << sol.isValid(str3) << endl;
    return 0;
}