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

class Solution1{
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return max(left, right) + 1;
    }
};

class Solution2{ //BFS
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        if(root != nullptr) q.push(root);

        int level = 0;
        while (!q.empty()) {
            for (int i = 0; i < q.size(); i++) { // 每輪要把 queue 清空，aka 每層
                TreeNode* node = q.front();
                q.pop();
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }
            level++;
        }
        return level;
    }
};

int main(){
    return 0;
}