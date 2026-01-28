#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class LRUCache1 { // O(n)
private:
    vector<pair<int, int>> lru; // 越後面的越 recently used
    int capacity;
public:
    LRUCache1(int capacity) {
        this->capacity = capacity; // this->capacity 是class 的 member variable
    }
    
    int get(int key) { // access 後要把它推到 vector 最後面
        for(int i = 0; i < lru.size(); i++){
            if(lru[i].first == key){
                pair<int, int> tmp = lru[i];
                lru.erase(lru.begin() + i);
                lru.push_back(tmp);
                return tmp.second;
            }
        }
        return -1;
    }
    
    void put(int key, int value){
        for(int i = 0; i < lru.size(); i++){
            if(lru[i].first == key){ // key 存在
                lru.erase(lru.begin() + i);
                lru.push_back({key, value});
                return;
            }
        }
        // key 不存在
        if(lru.size() == capacity){ // 滿了"才"要刪頭
            lru.erase(lru.begin());
        }
        lru.push_back({key, value});
    }
};

class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache2 { //O(1), doubly linked list, head 是 least, tail 是 most，再存在 map 內以快速查找 key
private:
    int capacity;
    unordered_map<int, Node*> lru; // 用 map 找 key 比較快，直接指向該 node
    Node* least;
    Node* most;

    void remove(Node* node) {
        Node *pre = node->prev;
        Node *nxt = node->next;
        pre->next = node->next;
        nxt->prev = pre;
    }

    void insert(Node* node) {
        Node *tmp = most->prev;
        tmp->next = node;
        node->prev = tmp;
        most->prev = node;
        node->next = most;
    }

public:
    LRUCache2(int capacity) {
        this->capacity = capacity;
        lru.clear();
        least = new Node(0, 0);
        most = new Node(0, 0);
        least->next = most;
        most->prev = least;
    }

    int get(int key) {
        if (lru.find(key) != lru.end()) { // key 存在
            Node* node = lru[key];
            remove(node);
            insert(node); // 重新插到最後
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (lru.find(key) != lru.end()) {
            remove(lru[key]);
        }
        Node* newNode = new Node(key, value);
        lru[key] = newNode;
        insert(newNode);

        if (lru.size() > capacity) {
            Node* tmp = least->next;
            remove(tmp);
            lru.erase(tmp->key);
            delete tmp;
        }
    }
};

int main(){
    return 0;
}