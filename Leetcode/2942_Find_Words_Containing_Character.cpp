#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution1 {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].size(); j++){
                if(words[i][j] == x){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution1 solution;
    vector<string> case1 = {"leet","code"};
    vector<string> case2 = {"abc","bcd","aaaa","cbc"};
    vector<int> ans1 = solution.findWordsContaining(case1, 'e');
    vector<int> ans2 = solution.findWordsContaining(case2, 'a');
    vector<int> ans3 = solution.findWordsContaining(case2, 'z');
    for(auto i:ans1){
        cout << i <<" ";
    }
    cout << endl;
    for(auto i:ans2){
        cout << i <<" ";
    }
    cout << endl;
    for(auto i:ans3){
        cout << i <<" ";
    }
    cout << endl;
    return 0;
}