#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution1 { // 把 linked list 每個 node 存到 set 找有沒有重複
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode *> mySet;
        ListNode *cur = head;
        while(cur != nullptr){
            if(mySet.find(cur) != mySet.end()) return true;
            mySet.insert(cur);
            cur = cur->next;
        }
        return false;
    }
};

class Solution2 { // 2 pointers，slow一次一格，fast一次兩格，在cycle內必定會相遇，因為假設兩者原本距離 n，每次移動，會減少1格的距離，n次移動後必定相遇
public:
    bool hasCycle(ListNode* head) {
        ListNode *slow = head, *fast = head;

        while(fast && fast->next){ // 沒有cycle的話，fast會先走到nullptr，因為一次兩格，所以也要確認fast->next
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};

int main(){
    Solution2 sol;
    return 0;
}