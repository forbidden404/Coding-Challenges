#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    int total = 0;
    while (N--) {
        string input;
        cin >> input;

        if (input.compare("report") == 0) {
            cout << total << endl;
        } else {
            int num;
            cin >> num;
            total += num;
        }
    }
	return 0;
}
