#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1 { // O(n^2)
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int leftHeight =  0, rightHeight = 0;

        if(root->left) leftHeight = BTHeight(root->left);
        if(root->right) rightHeight = BTHeight(root->right);

        if(abs(leftHeight - rightHeight) > 1) return false;

        return isBalanced(root->left) && isBalanced(root->right);
        }

private:
    int BTHeight(TreeNode *node){
        int left = 0, right = 0;

        if(node->left) left = BTHeight(node->left);
        if(node->right) right = BTHeight(node->right);
        
        return max(left, right) + 1;
    }
};

class Solution2 { // O(n)
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root)[0];
    }

private:
    vector<int> dfs(TreeNode* root) {
        if(!root) return {1, 0}; // {balanced, height}

        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);

        bool balanced = left[0] == 1 && right[0] == 1 && (abs(left[1] - right[1]) <= 1); // 自己的 subtree 都平衡 + 自己 root 後也平衡
        int height = 1 + max(left[1], right[1]);

        return {balanced, height};
    }
};

int main(){
    return 0;
}