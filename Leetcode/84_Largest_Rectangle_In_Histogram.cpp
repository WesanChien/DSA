#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution1 {
public:
    int largestRectangleArea(vector<int>& heights) { // 每根柱子去往左、右找，以它為最低高度去拓展的寬度
        int n = heights.size();
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            int height = heights[i];

            int rightMost = i + 1;
            while (rightMost < n && heights[rightMost] >= height) {
                rightMost++;
            }

            int leftMost = i - 1;
            while (leftMost >= 0 && heights[leftMost] >= height) {
                leftMost--;
            }

            rightMost--;
            leftMost++;
            maxArea = max(maxArea, height * (rightMost - leftMost + 1));
        }
        return maxArea;
    }
};

class Solution2 {
public:
    int largestRectangleArea(vector<int>& heights) { 
        int maxArea = 0;
        stack<pair<int, int>> stack; // pair: (index, height)

        for (int i = 0; i < heights.size(); i++) { // stack 內保持越來越高的 bar
            int start = i;
            while (!stack.empty() && stack.top().second > heights[i]) { // 如果新來的比較矮，在 pop 這些，之前要做的是
                pair<int, int> top = stack.top();
                int index = top.first;
                int height = top.second;
                maxArea = max(maxArea, height * (i - index)); // 這樣能確保 pop 兩根以上時，能以當前(就是最低)的高度，去正確算到寬度，包含到之前 pop 的
                start = index; // 把最後 pop 的 index 存起來給新 push 進來的用，方便之後計算 (heights.size()) - index)
                stack.pop();
            }
            stack.push({start, heights[i]});
        }

        while (!stack.empty()) {
            int index = stack.top().first;
            int height = stack.top().second;
            maxArea = max(maxArea, height * static_cast<int>(heights.size() - index)); // .size() 是 size_t 型別，要轉成 int
            stack.pop();
        }
        return maxArea;
    }
};

int main(){
    Solution2 sol;
    vector<int> heights1 = {7, 1, 7, 2, 2, 4};
    vector<int> heights2 = {1, 3, 7};
    cout << sol.largestRectangleArea(heights1) << endl;
    cout << sol.largestRectangleArea(heights2) << endl;
    return 0;
}