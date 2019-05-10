#include <bits/stdc++.h>

using namespace std;

// In this solution we save the columns and rows that have a zero so we can set those as zero later.
// There are a few optimizations that could have been done, such as using a Hash Table to avoid zeroing
// the same row or column twice. But we are going to see that there is a better solution for this problem.
void zeroMatrix(vector<vector<int>>& matrix) {
    if (matrix.size() * matrix[0].size() == 0) return;
    int zeroRows[matrix.size()];
    int zeroColumns[matrix[0].size()];

    int counter = 0;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (!matrix[i][j]) {
                zeroRows[counter] = i;
                zeroColumns[counter] = j;
                counter++;
            }
        }
    }

    for (int i = 0; i < counter; i++) {
        for (int j = 0; j < matrix.size(); j++) {
            matrix[j][zeroColumns[i]] = 0;
        }

        for (int j = 0; j < matrix[0].size(); j++) {
            matrix[zeroRows[i]][j] = 0;
        }
    }
}

// In this solution we store in the first column and row if there is a zero in our array, so later on we just
// need to check for the first row and column to erase the rest.
void zeroMatrixInPlace(vector<vector<int>>& matrix) {
    bool isCol = false;
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[i][0] == 0) isCol = true; // Here we need to check if there's one row that has a 0 in the first column so we can erase the first column later
        for (int j = 1; j < matrix[0].size(); j++) { // Starting from the second column, we have already processed the first one so we can store a zero there
            if (matrix[i][j] == 0) {                 // without losing information about our matrix
                matrix[i][0] = 0; 
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < matrix.size(); i++) {
        for (int j = 1; j < matrix[0].size(); j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) // Now we avoid the first row and column and set the rest as zero accordingly
                matrix[i][j] = 0;
        }
    }

    if (matrix[0][0] == 0) { // Check if we need to erase the first row
        for (int j = 0; j < matrix[0].size(); j++)
            matrix[0][j] = 0;
    }

    if (isCol) { // Check if we need to erase the first column
        for (int i = 0; i < matrix.size(); i++)
            matrix[i][0] = 0;
    }
}

int main() {
    // Read input
    string input;
    vector<vector<int>> v;
    while(getline(cin, input)) {
        istringstream iss(input);
        int num;
        vector<int> tmp;
        while (iss >> num) {
            tmp.push_back(num);
        }
        v.push_back(tmp);
    }

    // Write output
    zeroMatrixInPlace(v);
    for (auto t : v) {
        for (auto num : t) cout << num << " ";
        cout << endl;
    }
    return 0;
}
