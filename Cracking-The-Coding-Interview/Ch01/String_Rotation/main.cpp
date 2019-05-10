#include <bits/stdc++.h>

using namespace std;

bool isSubstring(string str1, string str2) {
    return str1.find(str2) != string::npos;
}

// This question is quite simple if you think about it. If we double str1, if str2 is a rotation of str1, it will be a substring of str1 + str1.
bool stringRotation(string str1, string str2) {
    if (str1.size() != str2.size()) return false;
    auto str = str1 + str1;
    return isSubstring(str, str2);
}

int main() {
    // Read input
    string left;
    cin >> left;

    string right;
    cin >> right;

    // Write output
    cout << right << " is " << (stringRotation(left, right) ? "": "not ") << "a rotation of " << right << endl;
    return 0;
}
