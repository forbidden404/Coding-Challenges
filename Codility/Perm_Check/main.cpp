#include <bits/stdc++.h>

using namespace std;

// If you know that the logical XOR operation between a number and itself will return zero, 
// if we apply the XOR operation to every number in our array and the indexes from 1 to N,
// the pairs of numbers that are equal are going to cancel each other out and there will only
// leave the number that is missing from the permutation, if there is any. Checking if the answer
// has returned 0 we can check if the array is a permutation or not.
int solution(vector<int>& v) {
    int answer = 0;
    for (int i = 0; i < v.size(); i++) answer ^= (i + 1) ^ v[i];
    return answer == 0 ? 1 : 0;
}

int main() {
    // Read input
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        vector<int> v;
        copy(istream_iterator<int>(iss), istream_iterator<int>(), back_inserter(v));

        // Write output
        cout << solution(v) << endl;
    }

    return 0;
}

