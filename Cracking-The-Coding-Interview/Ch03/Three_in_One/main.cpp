#include <bits/stdc++.h>

using namespace std;

// This question can become quite complex for an interview if you try to make it dynamic,
// so for now I will be restraining myself to only a fixed multi stack, where I will have
// one array and divide its values into three blocks that will be used for each stack.
// We just need to correctly locate the stack based on its index and then all operations
// should come out easily.
template <typename Value>
class FixedMultiStack {
    int numberOfStacks = 3;
    int stackCapacity;
    Value *values;
    int *sizes;

    int indexOfTop(int stackNum) {
        int offset = stackNum * stackCapacity;
        int size = sizes[stackNum];
        return offset + size - 1;
    }

public:
    FixedMultiStack(int stackSize) : stackCapacity(stackSize) {
        values = new Value[stackSize * numberOfStacks];
        sizes = new int[numberOfStacks];
    }

    bool isFull(int stackNum) {
        return sizes[stackNum] == stackCapacity; 
    }

    bool isEmpty(int stackNum) {
        return sizes[stackNum] == 0;
    }

    bool push(int stackNum, int value) {
        if (isFull(stackNum)) return false;

        sizes[stackNum]++;
        values[indexOfTop(stackNum)] = value;
        return true;
    }

    Value pop(int stackNum) {
        if (isEmpty(stackNum)) return Value();

        int topIndex = indexOfTop(stackNum);
        auto value = values[topIndex];
        sizes[stackNum]--;
        return value;
    }
    
    Value peek(int stackNum) {
        if (isEmpty(stackNum)) return Value();
        return values[indexOfTop(stackNum)];
    }
};

int main() {
    // Read input
    FixedMultiStack<int> stacks(128);
    
    for (int i = 0; i < 30; i++) {
        stacks.push(i % 3, i+1);
    }

    // Write output
    for (int i = 0; i < 3; i++) {
        while (!stacks.isEmpty(i)) {
            cout << stacks.pop(i) << " ";
        }
        cout << endl;
    }

    return 0;
}

