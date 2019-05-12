#include <bits/stdc++.h>

using namespace std;

// Complete the longestIncreasingSubsequence function below.
long memo[100005];

int longestIncreasingSubsequence(vector<int> arr) {
    memset(memo, 0, sizeof(memo));

    int longest = 0;
    for (int i = 0; i < arr.size(); i++) {
        int pos = lower_bound(memo, memo+longest, arr[i]) - memo;
        memo[pos] = arr[i];
        if (pos + 1 > longest) {
            longest = pos + 1;
        }
    }

    return longest;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = longestIncreasingSubsequence(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

