#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> s1;
    stack<int> s2;
    while (n--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            s1.push(x);
        } else {
            if (s2.empty()) {
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            if (!s2.empty()) {
                if (type == 2) s2.pop();
                if (type == 3) cout << s2.top() << endl;
            }

        }
    }

    return 0;
}

