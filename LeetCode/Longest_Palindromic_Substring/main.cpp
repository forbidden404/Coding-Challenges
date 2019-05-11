#include <bits/stdc++.h>

using namespace std;

// For this question, we need to think about the core of a palindromic string.
// The smallest palindromes you can have are of size 2 or 3, and each longer 
// substring will have a palindrome of size 2 or 3 in the middle.
// Once you found two adjacent characters that are the same, or two characters
// that are the same with only one letter in the middle, the next step to find a 
// bigger palindrome is to check for the neighbors of those chars, and if said
// neighbors are equal, you have a bigger palindrome there.
pair<int, int> rangePalindrome(string& s, int left, int right) {
    while (left >= 0 && right < s.size()) {
        if (s[right] == s[left]) {
            if (left == 0 || right == s.size() - 1) break;
            right++;
            left--;
        } else {
            right--;
            left++;
            break;
        }
    }

    return make_pair(left, right);
}

// In this question, we are looking for palindromes of size 2 and 3 in a linear scan
// of our string. If we find a candidate, we run our rangePalindrome function, that will
// check the neighbors of this palindrome and increase it if possible, returning a pair
// that contains a pair of indexes with the begin and end of our palindrome. Knowing that
// we just need to check if this new palindrome is bigger than the previous saved one and
// give our longest palindromic substring as an answer at the end of our linear scan.
string longestPalindrome(string s) {
    int maxLeft = 0;
    int maxRight = 0;
    for (int i = 1; i < s.size(); i++) {
        int left = i - 1;
        int right = i;
        if (s[right] == s[left]) {
            auto p = rangePalindrome(s, left, right);
            if (p.second - p.first > maxRight - maxLeft) {
                maxRight = p.second;
                maxLeft = p.first;
            }
        }

        left = i - 2;
        right = i;
        if (i > 2) {
            if (s[right] == s[left]) {
                auto p = rangePalindrome(s, left, right);
                if (p.second - p.first > maxRight - maxLeft) {
                    maxRight = p.second;
                    maxLeft = p.first;
                }
            }
        }
    }

    return s.substr(maxLeft, maxRight - maxLeft + 1);
}

int main() {
    string input;
    while (getline(cin, input)) {
        cout << longestPalindrome(input) << endl;
    }

    return 0;
}
