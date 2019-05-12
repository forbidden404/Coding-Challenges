#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int level = 0;

    int valleys = 0;
    bool isInValley = false;

    for (auto c : s) {
        if (c == 'D') {
            level--;
            if (!isInValley && level < 0) {
                valleys++;
                isInValley = true;
            }
        } else {
            level++;
            if (level == 0) isInValley = false;
        }
    }

    return valleys;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

