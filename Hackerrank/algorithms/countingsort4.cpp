#include <bits/stdc++.h>

using namespace std;

int main()
{
    long n;
    scanf("%ld", &n);

    string result[100];
    int x;
    char s[11];

    for (long i = 0; i < n / 2; i++) {
        scanf("%d", &x);
        scanf("%s", s);
        result[x] = result[x] + "- ";
    }

    for (long i = n / 2; i < n; i++) {
        scanf("%d", &x);
        scanf("%s", s);
        result[x] = result[x] + s + " ";
    }

    ios_base::sync_with_stdio(false);
    for (auto s : result) {
        cout << s;
    }
    cout << endl;

    return 0;
}

