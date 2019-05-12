#include <bits/stdc++.h>

using namespace std;

// We keep track of the value that we need to update our
// values when we get N + 1, and a current max whenever
// we need to update our max counter.
// That way we can just increase our numbers accordingly
// and in the end we update any element smaller than our
// max counter.
vector<int> solution(int N, vector<int>& A) {
    vector<int> v(N, 0);

    int maxCounter = 0;
    int currentMax = 0;

    for (auto num : A) {
        if (1 <= num && num <= N) {
            if (maxCounter > v[num-1])
                v[num-1] = maxCounter;
            v[num-1]++;
            currentMax = max(currentMax, v[num-1]);
        } else {
            maxCounter = currentMax;
        }
    }

    for (int i = 0; i < N; i++) {
        if (v[i] < maxCounter) v[i] = maxCounter;
    }

    return v;
}

int main() {
    // Read input
    vector<int> v;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));

    int N = v[v.size() - 1];
    v.pop_back();

    // Write output
    auto answer = solution(N, v);
    for (auto num : answer) { cout << num << " "; }
    cout << endl;

    return 0;
}
