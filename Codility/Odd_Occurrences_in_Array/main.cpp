#include <bits/stdc++.h>

using namespace std;

// If you know that the logical XOR operation between a number and itself will return zero, if we apply the XOR operation to every number in our array
// the pairs of numbers that are equal are going to cancel each other out and there will only leave the number with odd occurrences left as our answer.
int solution(vector<int>& v) {
    int answer = 0;
    for (auto num : v) { answer ^= num; }
    return answer;
}

int main() {
    // Read input
    vector<int> v;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));

    // Write output
    cout << solution(v) << endl;
    return 0;
}
