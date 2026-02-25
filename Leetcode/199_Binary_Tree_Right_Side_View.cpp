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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            for(int i = q.size(); i > 0; i--){ 
                TreeNode *tmp = q.front();
                q.pop();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);

                if(i == 1) res.push_back(tmp->val);
            }
        }
        return res;
    }
};

int main(){
    return 0;
}