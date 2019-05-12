#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the pageCount function below.
 */
int pageCount(int n, int p) {
    if (p == 1 || p == n) { return 0; }
    if (n % 2 == 1 && p == n - 1) { return 0; }
    int increasingNumber = p / 2;
    int decreasingNumber = n / 2 - p / 2;
    return min(increasingNumber, decreasingNumber);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = pageCount(n, p);

    fout << result << "\n";

    fout.close();

    return 0;
}

