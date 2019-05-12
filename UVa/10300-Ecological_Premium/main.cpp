#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int total = 0;
        while (n--) {
            int a, b, c;
            cin >> a >> b >> c;
            total += (a * c);
        }
        cout << total << endl;
    }
	return 0;
}
