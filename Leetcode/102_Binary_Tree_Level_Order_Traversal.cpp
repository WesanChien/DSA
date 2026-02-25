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
                if(tmp){ // 確認之前 enqueue 的不是 nullptr
                    level.push_back(tmp->val);
                    q.push(tmp->left); // nullptr push 進來也沒差，因為之後有先確認是非 nullptr
                    q.push(tmp->right);
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