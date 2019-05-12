#include <bits/stdc++.h>

using namespace std;

// Complete the getWays function below.
long memo[51][251];

long ways(long type, long value, vector<long>& c) {
    if (value == 0) return 1;
    if (value < 0 || type == c.size()) return 0;
    if (memo[type][value] != -1) return memo[type][value];
    return memo[type][value] = ways(type + 1, value, c) + ways(type, value - c[type], c);
}

long getWays(long n, vector<long> c) {
    memset(memo, -1, sizeof(memo));
    return ways(0, n, c);
}

int main()
{
    int n;
    int m;
    cin >> n >> m;

    vector<long> c(m);

    for (int i = 0; i < m; i++) {
        long c_item;
        cin >> c_item;

        c[i] = c_item;
    }

    long ways = getWays(n, c);
    cout << ways << endl;

    return 0;
}
