#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for(int i : stones){
            maxHeap.push(i);
        }
        while(maxHeap.size() > 1){
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();

            if(x > y) maxHeap.push(x - y);
        }
        if(maxHeap.size() == 0) return 0; // 也可直接 maxHeap.push(0)，如果是空的就會回傳 0
        return maxHeap.top();
    }
};

int main(){
    return 0;
}