#include <iostream>
#include <vector>

using namespace std;

class Solution1 { // O(m+n)
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double res;
        int m = nums1.size(), n = nums2.size(), total = m + n;
        vector<int> mergeNums;
        int i = 0, j = 0;

        while(i < m || j < n){ // 要考慮 1 空的時候，nums1[i] 會越界
            if(j == n || (i < m && nums1[i] <= nums2[j])){ // 這裡可以j==n時，必定i<m，但是可能是j<n&&i==m，不再次判斷i<m在nums1[i]時會越界
                mergeNums.push_back(nums1[i]);
                i++;
            }
            else {
                mergeNums.push_back(nums2[j]);
                j++;
            }
        }
        if(total % 2 == 1){ // odd
            int half = total / 2;
            res = mergeNums[half];
        }
        else{ // even
            int half = total / 2;
            res = (mergeNums[half] + mergeNums[half - 1]) / 2.0;
        }
        return res;
    }
};

class Solution2 { // O(log(m+n))
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        int total = A.size() + B.size();
        int half = (total + 1) / 2;

        if (B.size() < A.size()) {
            swap(A, B);
        }

        int l = 0;
        int r = A.size();
        while (l <= r) {
            int i = (l + r) / 2;
            int j = half - i;

            int Aleft = i > 0 ? A[i - 1] : INT_MIN;
            int Aright = i < A.size() ? A[i] : INT_MAX;
            int Bleft = j > 0 ? B[j - 1] : INT_MIN;
            int Bright = j < B.size() ? B[j] : INT_MAX;

            if (Aleft <= Bright && Bleft <= Aright) {
                if (total % 2 != 0) {
                    return max(Aleft, Bleft);
                }
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            } else if (Aleft > Bright) {
                r = i - 1;
            } else {
                l = i + 1;
            }
        }
        return -1;
    }
};

int main(){
    Solution1 sol;
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3};
    vector<int> nums3 = {1, 3};
    vector<int> nums4 = {2, 4};
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
    cout << sol.findMedianSortedArrays(nums3, nums4) << endl;
    return 0;
}