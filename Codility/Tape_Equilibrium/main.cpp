#include <bits/stdc++.h>

using namespace std;

// The solution is simple, keep the sum of left subarray starting as [0] , and the sum to the right,
// which will be [1..N). Calculate the absolute difference and for each number in [1..<N-1], just
// add that to the left subarray and remove from the right subarray, calculate the absolute difference
// and keep the smallest.
int solution(vector<int>& v) {
    int answer = 0;

    int sumLeft = v[0];
    int sumRight = accumulate(v.begin() + 1, v.end(), 0);

    answer = abs(sumRight - sumLeft);
    for (int i = 1; i < v.size() - 1; i++) {
        sumLeft += v[i];
        sumRight -= v[i];
        answer = min(answer, abs(sumRight - sumLeft));
    }

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
