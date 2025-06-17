#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int vecToInt(const vector<int> v){
    int number = 0;
    for(int i:v){
        number = number * 10 + i;
    }
    return number;
}

class Solution1 {
public:
    int minMaxDifference(int num) {
        int max, min, tmp, k = 0;
        vector<int> vnumMin, vnumMax;

        // 存成vector
        while(num > 0){
            tmp = num % 10;
            vnumMin.push_back(tmp);
            num /= 10;
        }
        reverse(vnumMin.begin(), vnumMin.end());
        vnumMax = vnumMin; // 不用for迴圈deep copy，stl寫好了

        // 改成最大
        while(k < vnumMax.size()){
            if(vnumMax[k] != 9){
                for (int i = k + 1; i < vnumMax.size(); i++) { 
                    if(vnumMax[i] == vnumMax[k]){
                        vnumMax[i] = 9;
                    }
                }
                vnumMax[k] = 9;
                break;
            }
            k++;
        }

        // 改成最小
        for (int i : vnumMin) {
            if(i == vnumMin[0]) i = 0;
        }
        vnumMin[0] = 0;
        
        max = vecToInt(vnumMax);
        min = vecToInt(vnumMin);

        return max - min;
    }
};

class Solution2 {
public:
    int minMaxDifference(int num) {
        string max = to_string(num);
        string min = max;
        int position = max.find_first_not_of('9');
        if (position != string::npos) { // position有值，不是not found
            char a = max[position];
            replace(max.begin(), max.end(), a, '9');
        }
        char b = min[0];
        replace(min.begin(), min.end(), b, '0');
        return stoi(max) - stoi(min);
    }
};

int main(){
    int num1 = 11891;
    int num2 = 90;
    int num3 = 900;
    Solution2 sol;
    int ans1 = sol.minMaxDifference(num1);
    cout << ans1 << endl;
    int ans2 = sol.minMaxDifference(num2);
    cout << ans2 << endl;
    int ans3 = sol.minMaxDifference(num3);
    cout << ans3 << endl;
    return 0;
}