#include <bits/stdc++.h>

using namespace std;

// The process of solving this question is to think of it as a sliding window that only contains the substring which we are analysing.
// If we know that from i to j - 1 we don't have repeating characters, we only need to check if j is in [i, j - 1) to know if [i, j) has all unique characters.
// If j isn't repeated, we now have a bigger substring than before, therefore we save the maximum between this new length and the biggest previous length saved.
// If j is repeated, we now know that the biggest substring starting from i ends in j - 1, so know we can start checking the next substring at j.
// Both i and j are actually used in our loop to keep track of the beginning of our sliding window and the end respectively.
int lengthOfLongestSubstring(string s) {
    int answer = 0;
    unordered_map<char, int> map;

    for (int i = 0, j = 0; j < s.size(); j++) {
        if (map.find(s[j]) != map.end()) // If j is found in our Hash Table, it will only be a repetition in [i, j - 1) if the index of the previous s[j] is ahead of i,
            i = max(map[s[j]], i);       // that is, it is inside the substring we are analysing, so we update i accordingly, since it could remain i if the other repetion occurred before i.
        answer = max(answer, j - i + 1); // If this is an extension of our previous substring or a new one, we need to check if it's bigger than the previous one.
        map[s[j]] = j + 1;               // And now we update the value of the s[j] in our Hash Table so if we find it again, we now start our new substring after this one.
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
