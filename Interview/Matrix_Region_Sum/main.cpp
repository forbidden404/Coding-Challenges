#include <bits/stdc++.h>

using namespace std;

// In this question we can simply sum each element for every query.
// Time complexity: O(M*N) every call
int matrixRegionSum1(vector<vector<int>> matrix,
        int tli, int tlj, int bri, int brj) {
    if (matrix.empty()) return 0;
    int sum = 0;
    for (int i = tli; i <= bri; i++) {
        for (int j = tlj; j <= brj; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

// To make it efficient for multiple queries, we can precompute
// the sum of every (x,y) position in relationt to (0,0).
// Having that, if we need to find the answer of the sum in the region
// delimited by (A, B), and (C, D) we just need to find OA, OB, OC, and OD.
// That way we can find the sum of (A, B)<=>(C,D) = OD - OB - OC + OA.
// Precomputed solution
vector<vector<int>> precomputeSums(vector<vector<int>> matrix) {
    vector<vector<int>> sums(matrix.size(), vector<int>(matrix[0].size(), 0));

    for (int i = 0; i < matrix[0].size(); i++)
        sums[0][i] = matrix[0][i];

    for (int i = 1; i < matrix.size(); i++)
        for (int j = 0; j < matrix[0].size(); j++)
            sums[i][j] = matrix[i][j] + sums[i-1][j];

    for (int i = 0; i < matrix.size(); i++)
        for (int j = 1; j < matrix[0].size(); j++)
            sums[i][j] += sums[i][j-1];

    return sums;
}

int matrixRegionSum(vector<vector<int>> matrix, 
        int tli, int tlj, int bri, int brj,
        vector<vector<int>> sums) {
    if (matrix.empty()) return 0;

    // OD
    int res = sums[bri][brj];

    // OB
    if (tli > 0)
        res -= sums[tli-1][brj];

    // OC
    if (tlj > 0)
        res -= sums[bri][tlj - 1];

    // OA
    if (tli > 0 && tlj > 0)
        res += sums[tli-1][tlj-1];

    return res;
}

int main() {
    vector<vector<int>> matrix{{1, 2, 3, 4, 6},
        {5, 3, 8, 1, 2},
        {4, 6, 7, 5, 5},
        {2, 4, 8, 9, 4}};

    int tli = 2, tlj = 2, bri = 3, brj = 4;
    cout << matrixRegionSum1(matrix, tli, tlj, bri, brj) << endl;

    tli = 0, tlj = 0, bri = 1, brj = 1;
    cout << matrixRegionSum1(matrix, tli, tlj, bri, brj) << endl;

    tli = 1, tlj = 2, bri = 3; brj = 3;
    cout << matrixRegionSum1(matrix, tli, tlj, bri, brj) << endl;

    cout << "Precomputed query: " << endl;
    auto sums = precomputeSums(matrix);
    tli = 2, tlj = 2, bri = 3, brj = 4;
    cout << matrixRegionSum(matrix, tli, tlj, bri, brj, sums) << endl;

    tli = 0, tlj = 0, bri = 1, brj = 1;
    cout << matrixRegionSum(matrix, tli, tlj, bri, brj, sums) << endl;

    tli = 1, tlj = 2, bri = 3; brj = 3;
    cout << matrixRegionSum(matrix, tli, tlj, bri, brj, sums) << endl;


    return 0;
}
