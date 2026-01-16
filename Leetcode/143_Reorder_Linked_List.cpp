#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution1 { // 把list存到array內，前後各一個pointer輪流放進新的list
public:
    void reorderList(ListNode* head) {
        if (!head) return;

        vector<int> tmp;
        ListNode *cur = head;

        while(cur != nullptr){
            tmp.push_back(cur->val);
            cur = cur->next;
        }

        int l = 1, r = tmp.size() - 1;
        ListNode *res = head;

        while(l <= r){
            res->next = new ListNode(tmp[r]);
            r--;
            res = res->next;
            if(l > r) break;
            res->next = new ListNode(tmp[l]);
            l++;
            res = res->next;
        }
    }
};

class Solution2 { // 用fast跟slow pointer把list分兩半，右半reverse，再來依序放完兩個list
public:
    void reorderList(ListNode* head) {
        ListNode *fast = head->next, *slow = head; // fast從第二個開始
        while(fast && fast->next){ // fast走到最後node或nullptr，slow就是剛好一半，所以slow->next就是右半的head
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *rightHalf = slow->next, *prev = nullptr;
        slow->next = nullptr; // 斷開兩半，避免 cycle

        while(rightHalf){ //reverse 右半
            ListNode *tmp = rightHalf->next;
            rightHalf->next = prev;
            prev = rightHalf;
            rightHalf = tmp;
        }

        // Merge兩半，右半的head是prev
        ListNode *first = head, *second = prev;
        while(second){
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second; 
            second->next = tmp1;
            first = tmp1; // 往內縮
            second = tmp2; // 往內縮
        }
        /*first, tmp1, ..., tmp2, second*/
    }
};

int main(){
    Solution2 sol;
    return 0;
}