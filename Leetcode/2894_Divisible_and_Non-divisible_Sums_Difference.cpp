#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
    int differenceOfSums(int n, int m) {
        int num = 0;
        for(int i = 1; i <= n; i++){
            if(i % m == 0){
                num -= i;
            }
            else{
                num += i;
            }
        }
        return num;
    }
};

class Solution2 {
public:
    int differenceOfSums(int n, int m) {
        int k = n / m;
        int num2 = m * ((1 + k) * k)/ 2;
        int num1 = (((1 + n) * n) / 2) - num2 * 2;
        return num1;
    }
};

int main(){
    Solution2 solution;
    int ans1 = solution.differenceOfSums(10, 3);
    int ans2 = solution.differenceOfSums(5, 6);
    int ans3 = solution.differenceOfSums(5, 1);
    cout << ans1 << endl;
    cout << ans2 << endl;
    cout << ans3 << endl;
}