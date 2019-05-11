#include <bits/stdc++.h>

using namespace std;

int mid(int a, int b, int c) {
    return (a > b ? (c > a ? a : (b > c ? b : c)) : (c > b ? b : (a > c ? a : c)));
}

int main() {
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        cout << "Case " << i << ": " << mid(a, b, c) << endl;
    }
	return 0;
}
