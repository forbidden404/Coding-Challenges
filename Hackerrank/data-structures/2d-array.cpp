#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int result = INT_MIN;

    for (int i = 0; i < arr.size() - 2; i++) {
        for (int j = 0; j < arr[i].size() - 2; j++) {
            int value = arr[i][j] + arr[i][j+1] + arr[i][j+2];
            value += arr[i+1][j+1];
            value += arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            if (value > result) result = value;
        }
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

