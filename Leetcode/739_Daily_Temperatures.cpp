#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Solution1 {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(temperatures[i] < temperatures[j]){
                    res[i] = j - i;
                    break;
                }
            }
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stack1;
        int n = temperatures.size();
        vector<int> res(n, 0); // {temp, index}
        for(int i = 0; i < n; i++){
            while(!stack1.empty() && temperatures[i] > stack1.top().first){
                auto pair = stack1.top();
                stack1.pop();
                res[pair.second] = i - pair.second;
            }
            stack1.push({temperatures[i], i});
        }
        return res;
    }
};


int main(){
    Solution2 sol;
    vector<int> temp1 = {30,38,30,36,35,40,28};
    vector<int> temp2 = {22,21,20};
    for(int i:sol.dailyTemperatures(temp1)){
        cout << i << " ";
    }
    cout << endl;
    for(int i:sol.dailyTemperatures(temp2)){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}