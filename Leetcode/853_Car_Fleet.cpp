#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pair;
        for (int i = 0; i < position.size(); i++) {
            pair.push_back({position[i], speed[i]});
        }
        sort(pair.rbegin(), pair.rend());
        vector<double> stack; // 不真的用 stack，因為之後要抓第二個 top 的值出來做比較

        for (auto p : pair) {
            stack.push_back((double)(target - p.first) / p.second); // 把所需時間 push 到 stack 內
            if (stack.size() >= 2 && stack.back() <= stack[stack.size() - 2]) // 如果 stack 有兩個，且 top <= second top，代表會相撞成同 fleet
            {
                stack.pop_back();
            }
        }
        return stack.size();
    }
};

int main(){
    Solution sol;
    vector<int> posi1 = {4, 1, 0, 7};
    vector<int> posi2 = {0, 4, 2};
    vector<int> speed1 = {2, 2, 1, 1};
    vector<int> speed2 = {2, 1, 3};
    cout << sol.carFleet(10, posi1, speed1) << endl;
    cout << sol.carFleet(10, posi2, speed2) << endl;
    return 0;
}