#include <bits/stdc++.h>

using namespace std;

// Complete the bigSorting function below.
bool cmpString(string &lhs, string &rhs) {
    if (lhs.size() < rhs.size()) return true;
    else if (lhs.size() > rhs.size()) return false;
    else {
        for (int i = 0; i < lhs.size(); i++) {
            if (lhs[i] < rhs[i]) { return true; }
            else if (lhs[i] > rhs[i]) { return false; }
        }
        return false;
    }
}

vector<string> bigSorting(vector<string> unsorted) {
    sort(unsorted.begin(), unsorted.end(), cmpString);
    return unsorted;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> unsorted(n);

    for (int i = 0; i < n; i++) {
        string unsorted_item;
        getline(cin, unsorted_item);

        unsorted[i] = unsorted_item;
    }

    vector<string> result = bigSorting(unsorted);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
<Paste>
