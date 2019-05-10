#include <bits/stdc++.h>

using namespace std;

// It is possible to answer this question with addition and subtraction, but that could lead to integer overflow.
// A better way to do it for integers is to use the logical XOR operator
void numberSwapper(int& a, int& b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

// Example:
// a = 2 => 0010, b = 3 => 0011
// a = 0010 ^ 0011 = 0001 = 1
// b = 0011 ^ 0001 = 0010 = 2
// a = 0001 ^ 0010 = 0011 = 3

int main() {
    // Read input
    vector<int> v;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));

    // Write output
    for (int i = 0; i < v.size() - 1; i += 2) {
        cout << v[i] << " \t<=>\t " << v[i+1] << endl;
        cout << "< \tSwap\t >" << endl;
        numberSwapper(v[i], v[i+1]);
        cout << v[i] << " \t<=>\t " << v[i+1] << endl << endl;
    }

    return 0;
}
