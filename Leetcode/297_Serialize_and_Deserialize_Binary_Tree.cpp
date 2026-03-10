#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec{
public:
    vector<string> res;
    string serialize(TreeNode* root) { // DFS(preorder) 把 tree 轉成 string
        if(!root) return "";

        res.push_back(to_string(root->val));
        dfsSerialize(root->left);
        dfsSerialize(root->right);

        return join(res, ",");
    }
    TreeNode* deserialize(string data) { // 把 string 轉回 tree
        if(data == "") return nullptr;

        vector<string> value = split(data, ',');
        int i = 0;
        return dfsDeserialize(value, i);
    }
private:
    void dfsSerialize(TreeNode* node){
        if(!node){
            res.push_back("N");
            return;
        }

        res.push_back(to_string(node->val));
        dfsSerialize(node->left);
        dfsSerialize(node->right);
    }

    TreeNode *dfsDeserialize(vector<string>& value, int& i){ // 一樣 DFS 把每個 value create Node 再串起來
        if(value[i] == "N"){
            i++;
            return nullptr;
        }

        TreeNode *node = new TreeNode(stoi(value[i]));
        i++;
        node->left = dfsDeserialize(value, i);
        node->right = dfsDeserialize(value, i);

        return node;
    }

    vector<string> split(const string &s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

    string join(const vector<string> &v, const string &delim) {
        ostringstream s;
        for (const auto &i : v) {
            if (&i != &v[0])
                s << delim;
            s << i;
        }
        return s.str();
    }
};

int main(){
    string str1 = "1,2,3,null,null,4,5"; // 轉成 "1,2,N,N,3,4,N,N,5,N,N"
    return 0;
}