#include <iostream>
#include <stack>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long res = 0, hours;

        do{
            hours = 0;
            res++;
            for(int i = 0; i < piles.size(); i++){
                hours += (piles[i] + (res - 1)) / res; // ceil(piles[i] / res)，加上 res - 1 等同於取 ceiling
            }
        }while(hours > h);

        return res;
    }
};

class Solution2 { // Binary Search 找 res 的可能值(1 ~ piles內最大值)
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = r; // 找符合的最小值，所以先設成可能最大的值

        while (l <= r) {
            int mid = (l + r) / 2;

            long long hours = 0;
            for (int p : piles) {
                hours += ceil(static_cast<double>(p) / mid); // 要用cmath的ceil()，要先轉成 double
            }
            if (hours <= h) { // 繼續找更小的
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};

int main(){
    Solution1 sol;
    vector<int> piles1 = {1, 4, 3, 2};
    vector<int> piles2 = {25, 10, 23, 4};
    vector<int> piles3 = {332484035,524908576,855865114,632922376,222257295,690155293,112677673,679580077,337406589,290818316,877337160,901728858,679284947,688210097,692137887,718203285,629455728,941802184};
    cout << sol.minEatingSpeed(piles1, 9) << endl;
    cout << sol.minEatingSpeed(piles2, 4) << endl;
    cout << sol.minEatingSpeed(piles3, 823855818) << endl;
    return 0;
}