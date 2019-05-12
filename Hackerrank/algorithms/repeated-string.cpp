#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long repetitions = n / s.length();
    long offset = n % s.length();
    long result = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'a') {
            result += repetitions;
            if (i < offset) {
                result++;
            }
        }
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

