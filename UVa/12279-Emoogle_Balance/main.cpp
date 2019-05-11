#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    int C = 1;
    while (cin >> N) {
        if (N == 0) break;
        int answer = 0;

        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            if (num == 0) answer--;
            else answer++;
        }

        cout << "Case " << C++ << ": " << answer << endl;
    }
	return 0;
}
