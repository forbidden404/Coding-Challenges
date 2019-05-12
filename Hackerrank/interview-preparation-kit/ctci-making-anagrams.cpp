#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    unordered_map<char, int> freqCount;
    for (char c : a) { freqCount[c]++; }
    for (char c : b) { freqCount[c]--; }

    int total = 0;
    for (auto elem : freqCount) {
        int value = elem.second;
        if (value < 0) { value *= -1; }
        total += value;
    }

    return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}

