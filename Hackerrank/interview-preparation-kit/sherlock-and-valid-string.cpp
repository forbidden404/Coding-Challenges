#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    unordered_map<char, int> charFrequency;
    vector<int> frequency(1);
    int max = 0;

    for (auto c : s) {
        if (charFrequency[c] != 0) {
            frequency[charFrequency[c]]--;
        }
        charFrequency[c]++;
        if (charFrequency[c] > max) {
            max = charFrequency[c];
            frequency.push_back(1);
        } else {
            frequency[charFrequency[c]]++;
        }
    }

    bool isInDanger = false;
    for (int i = 1; i < frequency.size(); i++) {
        if (i != frequency.size() - 1 && frequency[i] != 0) {
            if (isInDanger) { return "NO"; }
            if (i == 1 && frequency[i] == 1) {
                isInDanger = true;
            } else if (i == frequency.size() - 2) {
                if (frequency[i+1] == 1) {
                    return "YES";
                } else {
                    return "NO";
                }
            } else {
                return "NO";
            }
        } 
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

