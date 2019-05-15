#include <bits/stdc++.h>

using namespace std;

template <typename Value>
class Stack {
    vector<Value> data;

public:
    void push(Value x) { data.push_back(x); }
    bool isEmpty() { return data.empty(); }
    Value top() { return data.back(); }
    bool pop() { 
        if (isEmpty())
            return false;
        data.pop_back();
        return true;
    }
};
