#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class TimeMap1 {
public:
    unordered_map<string, unordered_map<int, string>> myMap;
    TimeMap1() {}
    
    void set(string key, string value, int timestamp) {
        // myMap[key][timestamp] = value; 
        myMap[key].insert({timestamp, value}); // 平均O(1)，但 worst case O(n)，因為 Hash collision
    }
    
    string get(string key, int timestamp) {
        if(myMap.find(key) == myMap.end()) return ""; // key 根本沒見過

        string res;
        int best = -1;
        for(auto i : myMap[key]){
            if(i.first <= timestamp && i.first > best){ // 存下當前有小到大，最靠近 timestamp 的 key，就可以存下最靠近 key 的 value
                best = i.first;
                res = i.second;
            }
        }
        return res;
    }
};

class TimeMap2 {
public:
    unordered_map<string, map<int, string>> myMap;
    TimeMap2() {}

    void set(string key, string value, int timestamp) {
        myMap[key].insert({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto it = myMap[key].upper_bound(timestamp); // 回傳「第一個大於 timestamp 的位置」，e.g. uppper_bound(99) == 100
        return it == myMap[key].begin() ? "" : prev(it)->second; // upper_bound 回到 begin() 代表所有都不符合規定(皆 > timestamp)
    }
};

int main(){
    TimeMap2 timeMap;
    timeMap.set("alice", "happy", 1);  // store the key "alice" and value "happy" along with timestamp = 1.
    timeMap.get("alice", 1);           // return "happy"
    timeMap.get("alice", 2);           // return "happy", there is no value stored for timestamp 2, thus we return the value at timestamp 1.
    timeMap.set("alice", "sad", 3);    // store the key "alice" and value "sad" along with timestamp = 3.
    timeMap.get("alice", 3);           // return "sad"
    timeMap.get("alice", 5);           // return "sad"
    return 0;
}