#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        
        cout << abs((((((((n * 567) / 9) + 7492) * 235) / 47) - 498) / 10) % 10) << endl;
    }

    return 0;
}
