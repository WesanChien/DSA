#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy; // 隨便設一個 dummy node
        ListNode *dnode = &dummy; // 用一個 pointer 指向 dummy node

        ListNode *p1 = list1, *p2 = list2; //p1, p2 分別指向兩個list head

        while(p1 && p2){
            if(p1->val <= p2->val){
                dnode->next = p1; // 要新增節點寫 dnode->next = new ListNode(p1->val);
                p1 = p1->next;
            }
            else{
                dnode->next = p2;
                p2 = p2->next;
            }
            dnode = dnode->next;
        }

        if(p1) dnode->next = p1; // list1 還有剩，全部接過去
        if(p2) dnode->next = p2; // list2 還有剩，全部接過去

        return dummy.next; // 不要 return 到那個 dummy node
    }
};

int main(){
    Solution sol;
    return 0;
}