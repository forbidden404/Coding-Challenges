#include <bits/stdc++.h>

using namespace std;

// We take the real space needed for the string and erase anything out of the string after it
// That way we can start writing on the string backwards, and every time we find a whitespace, we can write %20 at once
string urlify(string str, int length) {
    int spaces = 0;
    for (int i = 0; i < length; i++) if (str[i] == ' ') spaces++;

    int size = length + spaces * 2;
    if (str.size() > size)
        str.erase(size);

    size--;
    for (int i = length - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            str[size--] = '0';
            str[size--] = '2';
            str[size--] = '%';
        } else {
            str[size--] = str[i];
        }
    }
    return str;
}

int main() {
    // Read input
    string input;
    getline(cin, input);

    int length;
    cin >> length;

    // Write output
    cout << urlify(input, length) << endl;

    return 0;
}
