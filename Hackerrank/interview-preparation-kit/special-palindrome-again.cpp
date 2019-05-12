#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long palindromes(string &s, int j, int k, char c) {
    long total = 0;

    while (j >= 0 && k < s.size()) {
        if (s[j] == c && s[k] == c) {
            total++;
            j--;
            k++;
        } else {
            break;
        }
    }

    return total;
}

long substrCount(int n, string s) {
    long total = n;

    for (int i = 1; i < n; i++) {
        // check palindrome with 2 in the core
        if (s[i] == s[i-1]) {
            total++;
            int j, k;
            j = i - 2;
            k = i + 1;
            total += palindromes(s, j, k, s[i]);
        }
        if (i > 1) {
            // check palindrome with 3 in the core
            if (s[i] == s[i - 2]) {
                total++;
                int j, k;
                j = i - 3;
                k = i + 1;
                total += palindromes(s, j, k, s[i]);
            }
        }
    }

    return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

