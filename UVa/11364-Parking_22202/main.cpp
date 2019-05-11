#include <bits/stdc++.h>

using namespace std;

int main() {
    int cases;
    cin >> cases;
	while (cases--) {
        int stores;
        cin >> stores;

        int left = 1e9;
        int right = -1;
        while (stores--) {
            int store;
            cin >> store;
            left = min(left, store);
            right = max(right, store);
        }

        cout << 2 * (right - left) << endl;

	}
	return 0;
}
