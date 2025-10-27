#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution1
{ // Brutal Force用巢狀for跑每個substring，去找出最長不replace的substring
public:
    int characterReplacement(string s, int k)
    {
        int res = 0;

        for (int i = 0; i < s.size(); i++)
        {
            int mostFreq = 0; // 最常出現key的頻率
            unordered_map<char, int> freq;
            for (int j = i; j < s.size(); j++)
            {
                freq[s[j]]++;
                mostFreq = max(mostFreq, freq[s[j]]); // 找出最常見key的value(mostFreq)
                if (((j - i + 1) - mostFreq) <= k)
                {                                // j-i+1是substring長度
                    res = max(res, (j - i + 1)); // substring長度扣掉mostFreq長度仍<=k，代表足夠全部變成mostFreq的key
                }
            }
        }
        return res;
    }
};

class Solution2
{
public:
    int characterReplacement(string s, int k)
    {
        int res = 0;
        unordered_set<char> charSet(s.begin(), s.end());

        for (char c : charSet)
        {
            int l = 0, mostFreq = 0;
            for (int r = 0; r < s.size(); r++)
            {
                if(s[r] == c) mostFreq++;

                while ((r - l + 1) - mostFreq > k)
                {
                    if(s[l] == c) mostFreq--;
                    l++;
                }

                res = max(res, r - l + 1);
            }
        }
        return res;
    }
};

int main()
{
    Solution2 sol;
    string str1 = "XYYX";
    string str2 = "AAABABB";
    string str3 = "ABCBBB";
    cout << sol.characterReplacement(str1, 2) << endl;
    cout << sol.characterReplacement(str2, 1) << endl;
    cout << sol.characterReplacement(str3, 1) << endl;
    return 0;
}