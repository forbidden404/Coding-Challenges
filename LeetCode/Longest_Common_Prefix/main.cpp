#include <bits/stdc++.h>

using namespace std;

// The most straightforward answer to this question is just to do some
// vertical or horizontal scanning of each string and check when the 
// characters are different, but that still wouldn't be the best answer.
// To make this question really interesting, we can solve it using binary search.
// Our longest common prefix can only be as long as the smallest string of the
// dictionary we receive, so we can do a binary search from substrings from [0..middle).
// If the substring is a common prefix, we can continue enlarge our window by pushing
// our left to the right, which will increase middle, and if it's not a common prefix
// we can decrease middle by moving right to the left.
// Further improvements could be made in newer versions of C++, with C++20 we would be 
// able to use std::basic_string::starts_with to check for common prefixes and use
// std::basic_string_view so we avoid copying our substrings since we are doing read-only
// operations with it.
bool isCommonPrefix(vector<string>& strs, int length) {
    auto str = strs[0].substr(0, length);
    for (int i = 1; i < strs.size(); i++) {
        for (int j = 0; j < length; j++) {
            if (str[j] != strs[i][j]) return false;
        }
    }

    return true;
}

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    int minLen = INT_MAX;
    for (auto str : strs) {
        int size = str.size();
        minLen = min(minLen, size);
    }

    int left = 1;
    int right = minLen;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (isCommonPrefix(strs, middle))
            left = middle + 1;
        else
            right = middle - 1;
    }

    return strs[0].substr(0, (left + right) / 2);
}

int main() {
    // Read input
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);

        vector<string> strs;
        string word;
        while (iss >> word) {
            strs.push_back(word);
        }

        // Write output
        cout << longestCommonPrefix(strs) << endl;
    }


    return 0;
}
