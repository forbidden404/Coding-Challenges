#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
	while (t--) {
        int columns;
        cin >> columns;

        int diff = -1;
        bool canClose = true;
        while (columns--) {
            int a, b;
            cin >> a >> b;
            if (diff == -1) {
                diff = a - b;
            } else {
                if (diff != a - b) {
                    canClose = false;
                }
            }
        }
        cout << (canClose ? "yes" : "no") << endl;
        if (t != 0) cout << endl;
	}
	return 0;
}
