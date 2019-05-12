#include <bits/stdc++.h>

using namespace std;

int main() {
	string line;
    getline(cin, line);
	while (getline(cin, line)) {
        if (line.size() == 1) {
            if (line[0] == '1' || line[0] == '4') cout << "+" << endl; 
        } else if (line.size() == 2) {
            if (line.compare("78") == 0) cout << "+" << endl;
        } else if (line.substr(line.size() - 2).compare("35") == 0) {
            cout << "-" << endl;
        } else if (line[0] == '9' && line[line.size() - 1] == '4') {
            cout << "*" << endl;
        } else if (line.substr(0, 3).compare("190") == 0) {
            cout << "?" << endl;
        }
	}
	return 0;
}
