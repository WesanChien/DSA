#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return NULL;
        }

        Node *cur = head; // cur 是oldNode pointer
        unordered_map<Node*, Node*> myMap; // map 是 oldNode 對應 newNode

        while(cur){
            myMap[cur] = new Node(cur->val); // 先建立所有 newNode 給 old 對應
            cur = cur->next;
        }

        cur = head;
        while(cur){
            Node *copy = myMap[cur]; // copy 指向 newNode
            copy->next = cur->next ? myMap[cur->next] : NULL; // 再給 newNode 它的 next 跟 random
            copy->random = cur->random ? myMap[cur->random] : NULL;
            cur = cur->next;
        }

        return myMap[head];
    }
};

int main(){
    Solution sol;
    return 0;
}