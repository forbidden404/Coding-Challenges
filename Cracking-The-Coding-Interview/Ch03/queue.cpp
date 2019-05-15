#include <bits/stdc++.h>

using namespace std;

template <typename Value>
class Queue {
    vector<Value> data;
    int start;

public:
    Queue() : start(0) { }
    bool isEmpty() { return start >= data.size(); }
    bool enqueue(Value x) { data.push_back(x); return true; }
    bool dequeue() { 
        if (isEmpty())
            return false;
        start++;
        return true;
    }
    Value front() {
        return data[start];
    }
};
