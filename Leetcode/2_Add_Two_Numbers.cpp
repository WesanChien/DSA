#include <iostream>
#include <string>
#include <unordered_map>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *cur1 = l1, *cur2 = l2;
        int i1 = 1, i2 = 1, num1 = 0, num2 = 0;
        while(cur1){
            num1 += cur1->val * i1;
            i1 *= 10;
            cur1 = cur1->next;
        }
        
        while(cur2){
            num2 += cur2->val * i2;
            i2 *= 10;
            cur2 = cur2->next;
        }

        int sum = num1 + num2;
        string str = to_string(sum);
        ListNode *res = new ListNode(str[str.length() - 1] - '0'); // -'0' 才會正確把str轉成int
        ListNode *cur = res;

        for(int i = str.length() - 2; i >= 0; i--){
            cur->next = new ListNode(str[i] - '0');
            cur = cur->next;
        }
        return res;
    }
};

class Solution2 { // 每個node直接加，超過10的用carry記起來，下一個node要加一
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;

        int carry = 0; // 7+8 有一個十位數 1 要記著
        while (l1 || l2 || carry) {
            int v1 = (l1 != nullptr) ? l1->val : 0;
            int v2 = (l2 != nullptr) ? l2->val : 0;

            int val = v1 + v2 + carry;
            carry = val / 10;
            val = val % 10;
            cur->next = new ListNode(val);
            cur = cur->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
        return dummy->next;
    }
};

int main(){
    Solution sol;
    ListNode *l1 = new ListNode(1, new ListNode(2, new ListNode(3)));
    ListNode *l2 = new ListNode(4, new ListNode(5, new ListNode(6)));
    cout << sol.addTwoNumbers(l1, l2) << endl;
    return 0;
}