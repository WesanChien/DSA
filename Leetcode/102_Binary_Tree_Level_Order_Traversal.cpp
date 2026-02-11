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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> level;

            for(int i = q.size(); i > 0; i--){
                TreeNode *tmp = q.front();
                q.pop();
                if(tmp){ // 等同於再次確認 q 非空
                    level.push_back(tmp->val);
                    q.push(tmp->left); // nullptr push 進來也沒差
                    q.push(tmp->right); // nullptr push 進來也沒差
                }
            }
            if(!level.empty()) res.push_back(level);
        }
        return res;
    }
};

int main(){
    return 0;
}