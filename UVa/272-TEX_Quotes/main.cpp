#include <bits/stdc++.h>

using namespace std;

int main() {
    int turn = 0;
    string line;

    while(getline(cin, line)) {
        size_t found = -1;
        // Read line by line and look for quotes, if it's first quote, replace with ``, otherwise replace with ''
        while (found = line.find("\"", found + 1), (found != string::npos)) { 
            if (!turn) {
                line.replace(found, 1, "``");
            } else {
                line.replace(found, 1, "''");
            }
            turn = (turn + 1) % 2;
        }
        cout << line << "\n";
    }

    return 0;
}
