#include <bits/stdc++.h>

using namespace std;

// This question is straightforward, just keep track of the last
// value in case you need to do something like IX or IV.
int romanToInt(string s) {
    int result = 0;
    int lastValue = 1000;
    for (auto c: s) {
        int value = 0;
        if (c == 'M') {
            value = 1000;
        } else if (c == 'D') {
            value = 500;
        } else if (c == 'C') {
            value = 100;
        } else if (c == 'L') {
            value = 50;
        } else if (c == 'X') {
            value = 10;
        } else if (c == 'V') {
            value = 5;
        } else if (c == 'I') {
            value = 1;
        }
        if (lastValue < value) {
            result -= lastValue;
            result += (value - lastValue);
        } else {
            result += value;
        }
        lastValue = value;
    }

    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        cout << romanToInt(line) << endl;
    }

    return 0;
}
