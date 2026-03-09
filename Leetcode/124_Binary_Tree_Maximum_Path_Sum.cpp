#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution { 
public:
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
private: 
    int dfs(TreeNode *node){ /* DFS(Postorder) 考慮左右子 path 的最大值 return 給 parent，
                                但要考慮該 node 不需要加 parent 才是最大值的可能(同時也是包含 root，需要左右子 path 連通的可能)*/
        if(!node) return 0;

        int leftMax = dfs(node->left);
        int rightMax = dfs(node->right);
        leftMax = max(0, leftMax); // 確保負數要丟掉
        rightMax = max(0, rightMax);

        res = max(res, node->val + leftMax + rightMax); // res 要考慮(父 + 左右子)的這個 path 為最大的可能性
        return node->val + max(leftMax, rightMax); // 不 return res，要 return 左或右的單一 path，才能繼續延伸給 parent
    }
};

int main(){
    return 0;
}