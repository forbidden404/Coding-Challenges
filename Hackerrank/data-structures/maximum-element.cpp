#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Stack {
    Stack(int size) : top(0), size(size) {
        _array = new long[size];
    }

    void push(int v) {
        if (top + 1 == size) {
            long *tmp = (long *) realloc(_array, 2 * size * sizeof(long));
            if (tmp) {
                _array = tmp;
                size *= 2;
            } else {
                return; 
            }
        } 
        _array[top++] = v;
    }

    void pop() {
        top--;
        if (top < 0) top = 0;
    }

    void max() {
        long m = 0;
        for (int i = 0; i < top; i++) {
            m = ::max(m, _array[i]);
        }
        cout << m << endl;
    }

private:
    long *_array;
    int top;
    int size;
};

int main() {
    int n;
    cin >> n;

    Stack stack(n+1);

    while (n--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            stack.push(x);
        } else {
            if (type == 2) {
                stack.pop();
            } else {
                stack.max();
            }
        }
    }

    return 0;
}

