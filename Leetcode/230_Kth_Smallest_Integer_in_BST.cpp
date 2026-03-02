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
    vector<int> allNode;
    int kthSmallest(TreeNode* root, int k) {
        if(root) dfs(root);
        return allNode[k - 1];        
    }
private:
    void dfs(TreeNode *node){
        if(node->left) dfs(node->left);
        allNode.push_back(node->val);
        if(node->right) dfs(node->right);
    }
};

int main(){
    return 0;
}