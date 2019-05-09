#include <bits/stdc++.h>

using namespace std;

char toLower(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + ('a' - 'A');
    return c;
}

// Keep the frequency of every character, a palindrome can only have at most one character with odd occurrences,
// which would be the character in the middle of the string in an odd sized palindrome
bool palindromePermutation(string str) {
    unordered_map<char, int> frequencyCount;

    for (auto c : str) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) frequencyCount[toLower(c)]++;
    }

    bool hasOdd = false;
    for (auto p : frequencyCount) {
        if (p.second % 2 != 0) {
            if (hasOdd) return false;
            else hasOdd = true;
        }
    }
    return true;
}

int main() {
    // Read input and write output
    string inputLine;
    while (getline(cin, inputLine)) {
        cout << inputLine << " is " << (palindromePermutation(inputLine) ? "" : "not ") << "a palindrome permutation" << endl;       
    }

    return 0;
}
