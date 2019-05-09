#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;

    bool isFirstQuote = true;
    bool isFirstLine = true;
    while(getline(cin, line)) {
        if (!isFirstLine) cout << "\n";
        for (auto c : line) {
            if (c == '"') {
                if (isFirstQuote) {
                    isFirstQuote = false;
                    cout << "``";
                } else {
                    isFirstQuote = true;
                    cout << "''";
                }
            } else {
                cout << c;
            }
        }
        isFirstLine = false;
    }
    cout << "\n";

    return 0;
}
