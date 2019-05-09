#include <bits/stdc++.h>

using namespace std;

// If we are allowed to use additional data structures, we can use a HashMap to keep track of the frequency of each letter and check if they are equal for both
bool checkPermutation(string str1, string str2) {
    unordered_map<char, int> frequencyCount;

    for (auto c : str1) frequencyCount[c]++;
    for (auto c : str2) frequencyCount[c]--;
    for (auto p : frequencyCount) if (p.second != 0) return false;
    return true;
}

// If we can't use additional data structures, we could use an array based on the character enconding, but we can also sort our string and both strings should be equal.
bool checkPermutationSort(string str1, string str2) {
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1.compare(str2) == 0;
}

int main() {
    // Read input
    vector<string> v;
    copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(v));

    // Write output
    for (int i = 0; i < v.size() - 1; i += 2) {
        cout << v[i] << " and " << v[i+1] << (checkPermutation(v[i], v[i+1]) ? " are " : " are not ") << "permutation" << endl; 
    }

    return 0;
}
