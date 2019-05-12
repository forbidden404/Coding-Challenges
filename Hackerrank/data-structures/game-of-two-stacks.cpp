#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the twoStacks function below.
 */
int twoStacks(int x, vector<int> a, vector<int> b) {
    int sum = 0;
    int moves = 0;
    
    int i = 0, j = 0;
    while (i < a.size() && a[i] + sum <= x) {
        sum += a[i++];
    }
    moves = i;

    while (j < b.size() && i >= 0) {
        sum += b[j++];
        while (sum > x && i > 0) {
            i--;
            sum -= a[i];
        }
        if (sum <= x) moves = max(i+j, moves);
    }

    return moves;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int g;
    cin >> g;

    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n;
        int m;
        int x;
        cin >> n >> m >> x;

        vector<int> a(n);

        for (int a_itr = 0; a_itr < n; a_itr++) {
            int num;
            cin >> num;
            a[a_itr] = num;
        }

        vector<int> b(m);

        for (int b_itr = 0; b_itr < m; b_itr++) {
            int num;
            cin >> num;
            b[b_itr] = num;
        }

        int result = twoStacks(x, a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
