#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    int total = 0;
    for (int i = 1; i < s.length(); i++) {
        unordered_map<string, int> substrings;
        for (int j = 0; j+(i-1) < s.length(); j++) {
            auto substr = (s.substr(j, i));
            sort(substr.begin(), substr.end());

            const bool is_in = substrings.find(substr) != substrings.end();
            if (is_in) {
                substrings[substr]++;
                total += (substrings[substr] - 1);
            } else {
                substrings[substr] = 1;
            }
        }
        if (i == 1 && total == 0) return 0;
    }

    return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

