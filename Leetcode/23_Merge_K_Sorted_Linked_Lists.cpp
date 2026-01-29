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

class Solution1 { // O(n*k)
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){ // 用merge 2 sorted list 方式，k 個list 依序跟 resultant list 做 merge，做 K-1 次
        int k = lists.size() - 1;
        int i = 0;

        if (lists.empty()) return nullptr;
        while(k > 0){
            lists[i + 1] = mergeTwoLists(lists[i], lists[i + 1]);
            k--;
            i++;
        }
        return lists[i];
    }

private:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode *dnode = &dummy;

        while(list1 && list2){
            if(list1->val <= list2->val){
                dnode->next = list1;
                list1 = list1->next;
            }
            else{
                dnode->next = list2;
                list2 = list2->next;
            }
            dnode = dnode->next;
        }

        // 一邊走完了剩下的接過去
        if(list1){
            dnode->next = list1;
        }
        if(list2){
            dnode->next = list2;
        }
        return dummy.next;
    }
};

class Solution2 { // O(n*log k) with merger sort concept
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        while (lists.size() > 1) {
            vector<ListNode*> mergedLists;
            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = (i + 1) < lists.size() ? lists[i + 1] : nullptr;
                mergedLists.push_back(mergeTwoLists(l1, l2));
            }
            lists = mergedLists;
        }
        return lists[0];
    }

private:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode *dnode = &dummy;

        while(list1 && list2){
            if(list1->val <= list2->val){
                dnode->next = list1;
                list1 = list1->next;
            }
            else{
                dnode->next = list2;
                list2 = list2->next;
            }
            dnode = dnode->next;
        }

        // 一邊走完了剩下的接過去
        if(list1){
            dnode->next = list1;
        }
        if(list2){
            dnode->next = list2;
        }
        return dummy.next;
    }
};

int main(){
    // [[1,2,4],[1,3,5],[3,6]]
    // lists[0] = 1, 2, 4
    // lists[1] = 1, 3, 5
    // lists[2] = 3, 6
    return 0;
}