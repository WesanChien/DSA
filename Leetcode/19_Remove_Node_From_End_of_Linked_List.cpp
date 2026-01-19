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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *cur = head, *prev = nullptr;
        int listLength = 0;
        
        while(cur){ // 看 list 多長
            listLength++;
            cur = cur->next;
        }

        int N = listLength - n;
        if(N == 0) return head->next;

        cur = head;
        while(N){ // 把 cur 走到要刪的 Node
            if(prev) prev = prev->next;
            else prev = head;
           
            cur = cur->next;
            N--;
        }
        prev->next = cur->next;

        /* 如果你走到要刪除的前一個 node，就不用 prev 來連
        for(int i = 0; i < listLength - 1; i++){
            if(i + 1 == N){
                cur->next = cur->next->next;
                break;
            }
            cur = cur->next;
        }
        */

        return head;
    }
};

int main(){
    Solution sol;
    return 0;
}