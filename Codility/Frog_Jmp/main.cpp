#include <bits/stdc++.h>

using namespace std;

// The solution is simple math, we start at X and move by D until Y
// X + aD = Y, we need to find 'a' so => a = (Y - X)/D
// Now if a isn't an integer, we need to use the ceil function since if you
// need 2.2 jumps, you actually need 3 jumps, cause 2 won't be enough to
// pass Y.
int solution(int X, int Y, int D) {
    return ceil(1.0*(Y-X)/D);
}

int main() {
    // Read input
    int X, Y, D;
    cin >> X >> Y >> D;

    // Write output
    cout << solution(X, Y, D) << endl;
    return 0;
}
