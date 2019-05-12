#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    vector<vector<int>> array;
    array.reserve(n);

    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);

        array[i].reserve(k);
        for (int j = 0; j < k; j++) {
            int value;
            scanf("%d", &value);
            array[i].push_back(value);
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        cout << array[a][b] << endl;
    }
    return 0;
}

