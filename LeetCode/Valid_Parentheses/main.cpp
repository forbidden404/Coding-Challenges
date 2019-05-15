#include <bits/stdc++.h>

using namespace std;


// This question is straightforward. We are going to use a stack to keep track of the last
// open bracket, then if we find a closing bracket, we just need to check if it's closing
// a bracket of the same type, while keeping track of the open brackets left. At the end,
// for the string to be valid, all counters must be zero, which means that all open brackets
// were closed correctly.
bool isValid(string s) {
    int a = 0, b = 0, c = 0;

    stack<char> lastOpen;
    for (auto d : s) {
        if (d == '(') {
            lastOpen.push(d);
            a++;
        } else if (d == ')') {
            if (lastOpen.empty() || lastOpen.top() != '(') return false;
            lastOpen.pop();
            a--;
        } else if (d == '[') {
            lastOpen.push(d);
            b++;
        } else if (d == ']') {
            if (lastOpen.empty() || lastOpen.top() != '[') return false;
            lastOpen.pop();
            b--;
        } else if (d == '{') {
            lastOpen.push(d);
            c++;
        } else if (d == '}') {
            if (lastOpen.empty() || lastOpen.top() != '{') return false;
            lastOpen.pop();
            c--;
        }
    }

    return (!a && !b) && !c;
}

int main() {
    // Read input
    string input;
    while (cin >> input) {
        // Write output
        auto answer = isValid(input);
        cout << (answer ? "true" : "false") << endl;
    }

    return 0;
}
