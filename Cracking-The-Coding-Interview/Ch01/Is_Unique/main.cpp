#include <bits/stdc++.h>

using namespace std;

// If we are allowed to use additional data structures, we can just use a HashSet to check if a character is already present in the set of read characters
bool isUnique(string str) {
    unordered_set<char> seen;
    for (auto c : str) {
        if (seen.find(c) != seen.end()) return false; // This character was already present in the string.
        seen.insert(c);
    }
    return true;
}

// If we can't use additional data structures, our answer will depend on the character encoding used. Let's assume we receive a string using Extended ASCII encoding.
bool isUniqueASCII(string str) {
    if (str.size() > 256) return false; // String is bigger than actual character set, so there must be repetition

    int letters[256] = {};
    for (auto c : str) {
        int i = c;
        letters[i]++;
        if (letters[i] > 1) return false; // Character is repeated
    }

    return true;
}

int main() {
    // Read input
    vector<string> v;
    copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(v));

    // Write output
    for_each(v.begin(), v.end(), [](string s) { cout << s << (isUnique(s) ? " is unique" : " is not unique") << endl; });

    return 0;
}
