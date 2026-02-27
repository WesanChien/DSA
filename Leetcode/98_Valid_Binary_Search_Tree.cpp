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

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, INT_MIN, INT_MAX); // 每個 node 要確認 left/right boundary，一開始設正負 infinite
    }

    bool valid(TreeNode* node, int left, int right) {
        if(!node) return true;
        if(!(left < node->val && node->val < right)) return false; // node value 要確保大於 left boundary

        return valid(node->left, left, node->val) && valid(node->right, node->val, right); // 左子 node 要繼承父 node value 當 right boundary
    }
};

int main(){
    return 0;
}