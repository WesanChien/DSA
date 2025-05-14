#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution1 { // Time Limit Exceed: O(n^3)
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        bool used[1000] = {false}; // 避免重複輸出
        vector<int> ans;
        for(int i = 100; i < 1000; i+=2){
            for(int j = 0; j < n; j++){
                if(digits[j] == 0) continue; // 百位不為0
                for(int k = 0; k < n; k++){
                    if(j == k) continue;
                    for(int l = 0; l < n; l++){
                        if(l == j || l == k) continue;
                        if(i == 100*digits[j] + 10*digits[k] + digits[l] && !used[i]){
                            used[i] = true;
                            ans.push_back(i); // 不要用ans[i] = XXX這樣加
                        }
                    }
                }
            }
        }
    return ans;
    }
};

class Solution2{
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> sets; // 用 unordered_set<int> 比較快，因為查找是hash table的O(1)，set是RB tree
        int n = digits.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    if(i == j || j == k || i == k) continue;
                    int num = 100*digits[i] + 10*digits[j] + digits[k];
                    if(num >= 100 && num % 2 ==0){
                        sets.insert(num);
                    }
                }
            }
        }
        vector<int> ans;
        for(const int i : sets){
            ans.push_back(i);
        }
        // sort(ans.begin(), ans.end()); // set有排序，unordered_set要排序
        return ans;
    }
};

class Solution3{
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> count(10, 0); // digits 出現次數
        for (int d : digits) {
            count[d]++;
        }

        vector<int> ans;
        for (int num = 100; num < 1000; num += 2) {  // 只考慮三位偶數
            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            vector<int> tmp_count = count; // 每一輪都看自己有的 digit 夠不夠組出該偶數
            tmp_count[a]--;
            tmp_count[b]--;
            tmp_count[c]--;

            if (tmp_count[a] >= 0 && tmp_count[b] >= 0 && tmp_count[c] >= 0) { // 夠組出就會在 tmp_count 還 >= 0
                ans.push_back(num);
            }
        }
        return ans;
    }
};

int main() {
    Solution2 solution;
    vector<int> arr1 = {2,1,3,0};
    vector<int> ans1 = solution.findEvenNumbers(arr1);
    for(int i : ans1){
        cout << i <<" ";
    }
    cout << endl;
    vector<int> arr2 = {2,2,8,8,2};
    vector<int> ans2 = solution.findEvenNumbers(arr2);
    for(int i : ans2){
        cout << i <<" ";
    }
    cout << endl;
    vector<int> arr3 = {3,7,5};
    vector<int> ans3 = solution.findEvenNumbers(arr3);
    for(int i : ans3){
        cout << i <<" ";
    }
    return 0;
}