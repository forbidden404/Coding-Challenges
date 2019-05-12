#include <bits/stdc++.h>

using namespace std;

// We keep track of the leaves we have reached, every time
// we reach a new leaf we haven't before, we decrease our counter
// until we reach 0, then we have found our index. If not, we 
// return -1.
int solution(int X, vector<int>& A) {
    vector<bool> visited(A.size(), false);
    int uncovered = X;

    for (int i = 0; i < A.size(); i++) {
        if (visited[A[i] - 1] == false) {
            visited[A[i] - 1] = true;
            uncovered--;
            if (uncovered == 0) return i;
        }
    }

    return -1;
}

int main() {
    // Read input
    vector<int> v;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));

    int x = v[v.size() - 1];
    v.pop_back();

    // Write output
    cout << solution(x, v) << endl;
    return 0;
}
