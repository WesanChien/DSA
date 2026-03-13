#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, greater<pair<double, vector<int>>>> minHeap; // 存 <distance, [xi][yi]>
        
        for(int i = 0; i < points.size(); i++){
            minHeap.push({sqrt((points[i][0] * points[i][0]) + (points[i][1] * points[i][1])), points[i]}); //注意若要用 sqrt 要使用 double，不可 int
        }
        for(int i = k; i > 0; i--){
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return res;
    }
};

int main(){
    return 0;
}