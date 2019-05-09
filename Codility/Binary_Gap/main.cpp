#include <bits/stdc++.h>

using namespace std;

// Keep track of longest gap after the leftmost 1
int solution(int N) {
    int longestGap = 0;
    int currentGap = -1; // We start currentGap as -1 so we can ignore all the zeroes coming before the rightmost 1

    while (N > 0) {
        if (N & 1) { // We are checking the rightmost element here
            longestGap = max(longestGap, currentGap);
            currentGap = 0;
        } else if (currentGap != -1) {
            currentGap++;
        }

        // Right-shifting N so we ignore the processed bit
        N >>= 1;
    }

    return longestGap;
}

// Another solution would be to traverse each bit in a for loop if we know the amount of bits in the integer. The question expects a 32 bit integer.
int solution2(int N) {
    int longestGap = 0;
    int currentGap = -1;
        
    // Both solutions are equal when it comes to their concept, but the first one changes the number locally in the function, while
    // this solution by knowing the length of the bits, can traverse bit by bit.
    for (int i = 0; i < 32; i++) {
        if (N & (1 << i)) { // Bit is set 
            longestGap = max(longestGap, currentGap);
            currentGap = 0;
        } else if (currentGap != -1) {
            currentGap++;
        }
    }

    return longestGap;
}

int main() {
    // Read input
    vector<int> v;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));

    // Write output
    for_each(v.begin(), v.end(), [](int num) { cout << solution2(num) << endl; });
    return 0;
}
