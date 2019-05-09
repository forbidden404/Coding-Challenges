#include <bits/stdc++.h>

using namespace std;

void numberSwapper(int& a, int& b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

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
