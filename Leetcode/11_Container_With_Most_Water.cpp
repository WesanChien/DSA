#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution1 {
public:
    int maxArea(vector<int>& heights) {
        int width = heights.size() - 1;
        int l = 0, r = width;
        int area = 0;

        while(width != 0){ 
            if((width * min(heights[l], heights[r])) > area){
                area = width * min(heights[l], heights[r]);
            }
            else{
                width--;
                if(heights[l] < heights[r]) l++;
                else r--;
            }
        }
        return area;
    }
};

class Solution2 { // 同觀念簡潔code版
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int area = 0;

        while(l < r){
            int tmp = (r - l) * min(heights[l], heights[r]);
            area = max(area, tmp);

            if(heights[l] < heights[r]) l++;
            else r--;
        }
        return area;
    }
};

int main(){
    Solution2 sol;
    vector<int> numbers1 = {1, 7, 2, 5, 4, 7, 3, 6};
    vector<int> numbers2 = {2, 2, 2};
    vector<int> numbers3 = {0, 0, 0, 0};
    cout << sol.maxArea(numbers1) << endl;
    cout << sol.maxArea(numbers2) << endl;
    cout << sol.maxArea(numbers3) << endl;
    return 0;
}