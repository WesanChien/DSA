#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), res = 0;
        for(int i = 0; i < n; i++){
            for(int j = n - 1; j > i; j--){
                if((prices[j] - prices[i]) > res){
                    res = prices[j] - prices[i];
                }
            }
        }

        return res;
    }
};

class Solution2 { // Two Pointer
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1, maxProfit = 0;
        while(r < prices.size() - 1){
            if(prices[r] > prices[l]){
                int profit = prices[r] - prices[l];
                maxProfit = max(profit, maxProfit);
            }
            else{
                l = r;
            }
            r++;
        }
        return maxProfit;
    }
};

int main() {
    Solution2 sol;
    vector<int> arr1 = {7, 1, 5, 3, 6, 4};
    cout << sol.maxProfit(arr1) << endl; 
    vector<int> arr2 = {6, 4, 3, 1};
    cout << sol.maxProfit(arr2) << endl; 
    return 0;
}