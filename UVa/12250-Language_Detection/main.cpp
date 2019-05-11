#include <bits/stdc++.h>

using namespace std;

int main() {
	string line;
    int t = 1;
	while (getline(cin, line)) {
        if (line.compare("#") == 0) break;
        string answer = "";

        if (line.compare("HELLO") == 0) {
            answer = "ENGLISH";
        } else if (line.compare("HOLA") == 0) {
            answer = "SPANISH";
        } else if (line.compare("HALLO") == 0) {
            answer = "GERMAN";
        } else if (line.compare("BONJOUR") == 0) {
            answer = "FRENCH";
        } else if (line.compare("CIAO") == 0) {
            answer = "ITALIAN";
        } else if (line.compare("ZDRAVSTVUJTE") == 0) {
            answer = "RUSSIAN";
        } else {
            answer = "UNKNOWN";
        }

        cout << "Case " << t++ << ": " << answer << endl;
	}
	return 0;
}
