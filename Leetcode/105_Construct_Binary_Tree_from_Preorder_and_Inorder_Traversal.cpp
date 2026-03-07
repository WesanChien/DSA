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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        auto mid = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin(); // mid 是 root value 的 index，代表左子樹有多少 node
        /*也可這樣寫
        auto tmp = find(inorder.begin(), inorder.end(), preorder[0]); // 印出 tmp 值要寫 cout << *tmp
        int mid = distance(inorder.begin(), tmp);
        */
        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + mid + 1); // 把 preorder、inorder 切成左子、右子，且刪除 root
        vector<int> rightPre(preorder.begin() + mid + 1, preorder.end());
        vector<int> leftIn(inorder.begin(), inorder.begin() + mid);
        vector<int> rightIn(inorder.begin() + mid + 1, inorder.end()); // C++ iterator 是 [first, last)，.end() 不是最後的index value，而是後面的 derefernce

        /*DFS 下去遞迴，串出整個 binary tree*/
        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);
        return root;
    }
};

int main(){
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    return 0;
}