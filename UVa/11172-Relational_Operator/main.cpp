#include <bits/stdc++.h>

using namespace std;

int main() {
    int cases;
    cin >> cases;
	while (cases--) {
        int a, b;
        cin >> a >> b;
        if (a == b) cout << "=\n";
        else if (a < b) cout << "<\n";
        else if (a > b) cout << ">\n";
	}
	return 0;
}
