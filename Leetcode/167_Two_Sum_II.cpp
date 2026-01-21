#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution1 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int n = numbers.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(numbers[j] == target - numbers[i]){
                    ans.push_back(i + 1);
                    ans.push_back(j + 1);
                }
            }
        }
        return ans;
    }
};

class Solution2 { //兩邊夾起來
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int i = 0, j = numbers.size() - 1;
        while(i < j){
            if(numbers[i] + numbers[j] == target){
                ans.push_back(i + 1);
                ans.push_back(j + 1);
                return ans;
            }
            else if(numbers[i] + numbers[j] > target){
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};

class Solution3 { // 用unordered_map的find只需O(1)的方法找diff存在與否
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mp;
        int n = numbers.size();
        for(int i = 0; i < n; i++){
            mp[numbers[i]] = i + 1; // 存1-index起來
        }
        for(int i = 0; i < n; i++){
            int diff = target - numbers[i];
            if(mp.count(diff)){
                return {i + 1, mp[diff]};
            }
        }
    }
};

int main(){
    Solution3 sol;
    vector<int> numbers1 = {1, 2, 3, 4};
    vector<int> numbers2 = {1, 2, 2, 4, 5};
    for(int i:sol.twoSum(numbers1, 3)){
        cout << i << " ";
    }
    cout << endl;
    for(int i:sol.twoSum(numbers2, 4)){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}