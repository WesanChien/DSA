#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class MedianFinder1 {
public:
    vector<int> stream;
    
    void addNum(int num) {
        stream.push_back(num);
        sort(stream.begin(), stream.end());
    }
    
    double findMedian() {
        int n = stream.size();
        if(n % 2 == 1){
            int mid = n / 2;
            return stream[mid];
        }
        else{
            double res = (stream[n / 2 - 1] + stream[n / 2]) / 2.0;
            return res;
        }
    }
};

class MedianFinder2 {
    priority_queue<int> smallHeap; // maxHeap
    priority_queue<int, vector<int>, greater<int>> largeHeap; // minHeap
public:
    void addNum(int num) {
        smallHeap.push(num);
        if(!largeHeap.empty() && smallHeap.top() > largeHeap.top()){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if(smallHeap.size() > largeHeap.size() + 1){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if(largeHeap.size() > smallHeap.size() + 1){
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }

    double findMedian(){
        if(smallHeap.size() == largeHeap.size()) {
            return (largeHeap.top() + smallHeap.top()) / 2.0;
        } 
        else if(smallHeap.size() > largeHeap.size()){
            return smallHeap.top();
        }
        else{
            return largeHeap.top();
        }
    }
};

int main(){
    MedianFinder1 medianFinder;
    medianFinder.addNum(1);    // arr = [1]
    medianFinder.findMedian(); // return 1.0
    medianFinder.addNum(3);    // arr = [1, 3]
    medianFinder.findMedian(); // return 2.0
    medianFinder.addNum(2);    // arr[1, 2, 3]
    medianFinder.findMedian(); // return 2.0
    return 0;
}