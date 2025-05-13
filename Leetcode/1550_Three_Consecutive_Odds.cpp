#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int pivot = 0;
        while(pivot + 2 < arr.size()){
            while(pivot + 2 < arr.size() && arr[pivot] % 2 == 0){ // 多加pivot+2，避免arr[j、k]越界
                pivot++;
            }
            if(pivot + 2 < arr.size() && arr[pivot + 1] % 2 == 1 && arr[pivot + 2] % 2 == 1){
                return true;
            }
            else
                pivot+=2;
        }   
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> arr1 = {2, 6, 4, 1};
    cout << solution.threeConsecutiveOdds(arr1) << endl; 
    vector<int> arr2 = {1, 2, 34, 3, 4, 5, 7, 23, 12};
    cout << solution.threeConsecutiveOdds(arr2) << endl;
    vector<int> arr3 = {1, 1, 1};
    cout << solution.threeConsecutiveOdds(arr3) << endl;
    return 0;
}