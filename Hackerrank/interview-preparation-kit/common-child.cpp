#include <bits/stdc++.h>

using namespace std;

int memo[5001][5001];

int commonChild(string s1, string s2) {
    memset(memo, 0, sizeof(memo));

    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i-1] == s2[j-1])
                memo[i][j] = memo[i-1][j-1] + 1;
            else
                memo[i][j] = max(memo[i][j-1], memo[i-1][j]);
        }
    }

    return memo[s1.size()][s2.size()];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}

