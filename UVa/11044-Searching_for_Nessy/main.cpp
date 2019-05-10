#include <bits/stdc++.h>

using namespace std;

int main() {
    int cases;
    cin >> cases;
	while (cases--) {
        int a, b;
        cin >> a >> b;

        int answer = (a / 3) * (b / 3);
        cout << answer << endl;
	}
	return 0;
}
