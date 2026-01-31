#include <iostream>
#include <unordered_map>
#include <vector>

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* groupPrev = dummy;

        while (1) {
            ListNode *kth = getKth(groupPrev, k); // getKth 會回傳從 dummy 開始的 kth node，也就是 reverse 完往左串的新 head node(*kth)
            if(kth == nullptr) break; // 不夠 k 個做 reverse
            ListNode* groupNext = kth->next; //groupNext 指向剩下往右串的 new head

            ListNode *prev = kth->next; // prev 也指向往右串的 new head
            ListNode *cur = groupPrev->next; // 當下是同head，之後是指向往左串的 tail

            while(cur != groupNext) { // reverse 前 k nodes
                ListNode* tmp = cur->next;
                cur->next = prev; // 不指向 null，直接串到之後往右串的 new head
                prev = cur;
                cur = tmp;
            }

            ListNode* tmp = groupPrev->next;
            groupPrev->next = kth; // dummy 指向往左串 new head
            groupPrev = tmp;
        }
        return dummy->next;
    }
private:
    ListNode* getKth(ListNode* cur, int k) {
        while (cur && k > 0) {
            cur = cur->next;
            k--;
        }
        return cur;
    }
};

int main(){
    return 0;
}