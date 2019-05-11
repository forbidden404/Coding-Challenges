#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        string input;
        cin >> input;

        if (input.size() == 5) {
            cout << 3 << endl;
        } else {
            if ((input[0] == 'o' && input[1] == 'n') || (input[0] == 'o' && input[2] == 'e') 
                    || (input[1] == 'n' && input[2] == 'e'))
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
    }
	return 0;
}
