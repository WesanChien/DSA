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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        BTHeight(root, diameter);
        return diameter;
    }
private:
    int BTHeight(TreeNode *root, int &diameter){ // 要帶 diameter 去比較，因可能 diameter 比 treeHeight 大(e.g. [1, 2, 3, 4, 5, 6, 7] 的 complete BT)
        if(!root) return 0;

        int leftHeight = BTHeight(root->left, diameter);
        int rightHeight = BTHeight(root->right, diameter);
        diameter = max(diameter, leftHeight + rightHeight);
        
        return max(leftHeight, rightHeight) + 1;
    }
};

int main(){
    return 0;
}