#include <iostream>
#include <stack>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution1 {
public:
    bool isOperator(string &s){
        unordered_set<string> ops = {"+", "-", "*", "/"};
        return ops.count(s) > 0;
    }
    int applyOp(int a, int b, string s){
        if(s == "+") return a + b;
        if(s == "-") return a - b;
        if(s == "*") return a * b;
        if(s == "/" && b != 0) return a / b;
        else throw runtime_error("Invalid operator");
    }
    int evalRPN(vector<string>& tokens) {
        stack<string> stack1;
        int n = tokens.size();
        for(int i = 0; i < n; i++){
            if(!isOperator(tokens[i])) stack1.push(tokens[i]);
            else {
                int b = stoi(stack1.top());
                stack1.pop();
                int a = stoi(stack1.top());
                stack1.pop();
                string tmp = to_string(applyOp(a, b, tokens[i]));
                stack1.push(tmp);
            }
        }
        return stoi(stack1.top());
    }
};

class Solution2 {
public:
    int dfs(vector<string> &tokens){ // 一定要 call by ref，才不會 pop_back 後，之後 call 的 recursion 仍然是完整的 tokens
        string lastToken = tokens.back();
        tokens.pop_back();

        if(lastToken != "+" && lastToken != "-" && lastToken != "*" && lastToken != "/") return stoi(lastToken);

        int right = dfs(tokens);
        int left = dfs(tokens);

        if(lastToken == "+") return left + right;
        else if(lastToken == "-") return left - right;
        else if(lastToken == "*") return left * right;
        else return left / right;
    }
    int evalRPN(vector<string>& tokens) {
        return dfs(tokens);
    }
};

int main(){
    Solution2 sol;
    vector<string> tokens1 = {"1", "2", "+", "3", "*", "4", "-"}; // ((1+2)*3)-4
    vector<string> tokens2 = {"5", "2", "-", "4", "1", "+", "*", "-5", "/"}; // ((5-2)*(4+1))/5
    // vector<string> tokens3 = {"5", "2", "-", "4", "1", "+", "*", "0", "/"}; // ((5-2)*(4+1))/5
    cout << sol.evalRPN(tokens1) << endl;
    cout << sol.evalRPN(tokens2) << endl;
    // cout << sol.evalRPN(tokens3) << endl;
    return 0;
}