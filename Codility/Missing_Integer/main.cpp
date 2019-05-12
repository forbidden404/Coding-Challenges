#include <bits/stdc++.h>

using namespace std;

// We add every item read from A into a Hash Set,
// then we just need to check, starting from 1,
// which one is the first number to not be in the
// Hash Set.
int solution(vector<int>& A) {
    unordered_set<int> seen;
    for (auto num : A) { seen.insert(num); }
    int i = 1;
    while (true) {
        if (seen.find(i) == seen.end()) return i;
        i++;
    }
    return 0;
}

int main() {
    // Read input
    string line;
    while (getline(cin, line)) {
        vector<int> v;
        istringstream iss(line);
        copy(istream_iterator<int>(iss), istream_iterator<int>(), back_inserter(v));

        // Write output
        cout << solution(v) << endl;
    }

    return 0;
}
