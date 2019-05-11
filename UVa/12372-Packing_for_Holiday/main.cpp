#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    int C = 1;
    while (N--) {
        string answer;
        int L, W, H;
        cin >> L >> W >> H;

        if (L <= 20 && W <= 20 && H <= 20) answer = "good";
        else answer = "bad";

        cout << "Case " << C++ << ": " << answer << endl;
    }
	return 0;
}
