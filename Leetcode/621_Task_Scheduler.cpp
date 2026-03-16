#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution{
public:
    int leastInterval(vector<char>& tasks, int n){
        vector<int> taskCount(26, 0);
        for(char a : tasks){
            taskCount[a - 'A']++;
        }

        priority_queue<int> maxHeap;
        for(int cnt : taskCount){
            if(cnt > 0) maxHeap.push(cnt);
        }

        int time = 0;
        queue<pair<int, int>> q; // <count, timing that ready to get back to queue>

        while(!maxHeap.empty() || !q.empty()){
            time++;

            if(maxHeap.empty()){
                time = q.front().second; // maxHeap 空了，就必須等到 q 內第一個被加進去的可回歸 timing
            }
            else{
                int cnt = maxHeap.top() - 1; // task 被安排
                maxHeap.pop();
                if(cnt > 0){
                    q.push({cnt, time + n}); // task 還沒被做完，把他加到 q <剩餘次數, 可回歸時間>
                }
            }

            if(!q.empty() && q.front().second == time){ // 對應 time = q.front().second;，時間到 q 的第一個 task 可回歸時間
                maxHeap.push(q.front().first); // 加回到maxHeap
                q.pop();
            }
        }
        return time;
    }
};

int main(){
    vector<char> tasks1 = {'A', 'A', 'B', 'B', 'B', 'C'};
    return 0;
}