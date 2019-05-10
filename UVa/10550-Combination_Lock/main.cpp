#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c, d;
	while ((cin >> a >> b  >> c >> d), (a || b || c || d)) {
		int answer = 1080 + ((a - b + 40) % 40 + (c - b + 40) % 40 + (c - d + 40) % 40) * 9; 
		cout << answer << "\n";
	}
	return 0;
}
