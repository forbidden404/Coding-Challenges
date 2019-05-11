#include <bits/stdc++.h>

using namespace std;

int main() {
    string N;
    int C = 1;
    while (cin >> N) {
        if (N[0] == '*') break;
        string answer; 

        if (N.compare("Hajj") == 0) {
            answer = "Hajj-e-Akbar";
        } else {
            answer = "Hajj-e-Asghar";
        }

        cout << "Case " << C++ << ": " << answer << endl;
    }
	return 0;
}
