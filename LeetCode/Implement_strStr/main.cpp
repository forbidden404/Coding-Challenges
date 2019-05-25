#include <bits/stdc++.h>

using namespace std;

// We could just simply return string::find()? That would be too easy, wouldn't it?
// So for the actual solution, we just keep track of where we are checking our needle
// with the ith character of haystack. While it's the same, we keep increasing the index
// of our needle, if it's not, then we restart our index and move i back to the position 
// right after we started checking if our needle with the haystack.
int strStr(string haystack, string needle) {
    if (needle == "") return 0;
    else {
        int index = 0;
        for (int i = 0; i < haystack.size(); i++) {
            if (needle[index] == haystack[i]) {
                if (index == needle.size() - 1) {
                    return i - index;
                }
                index++;
            } else {
                i = i - index;
                index = 0;
            }
        }
        return -1;
    }
}

int main() {
    // Read input
    string haystack, needle;

    while (cin >> haystack >> needle) {
        // Write output
        cout << strStr(haystack, needle) << endl;
    }

    return 0;
}
