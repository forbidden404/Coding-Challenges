#include <bits/stdc++.h>

using namespace std;

// The process of solving this question is to think of it as a sliding window that only contains the substring which 
// we are analysing. If we know that from i to j - 1 we don't have repeating characters, we only need to check if j is in
// [i, j - 1) to know if [i, j) has all unique characters. If j isn't repeated, we now have a bigger substring than before,
// therefore we save the maximum between this new length and the biggest previous length saved. If j is repeated, we now
// know that the biggest substring starting from i ends in j - 1, so know we can start checking the next substring at
// the index after the first index of the repeated character.
// Both i and j are actually used in our loop to keep track of the beginning of our sliding window and the end respectively.
int lengthOfLongestSubstring(string s) {
    int answer = 0;
    unordered_map<char, int> map;

    for (int i = 0, j = 0; j < s.size(); j++) {
        if (map.find(s[j]) != map.end()) // If j is found in our Hash Table, it will only be a repetition in [i, j - 1) 
            i = max(map[s[j]], i);       // if the index of the previous s[j] is ahead of i, that is, it is inside the 
        answer = max(answer, j - i + 1); // substring we are analysing, so we update i accordingly. 
        map[s[j]] = j + 1;               // We always have to keep track of the index after the last occurrence of s[j].
    }

    return answer;
}

int main() {
    string line;
    while (getline(cin, line)) {
        cout << lengthOfLongestSubstring(line) << endl;
    }

    return 0;
}
