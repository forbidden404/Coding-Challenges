#include <bits/stdc++.h>

using namespace std;

// We can do this question in-place if we think as layers, so we can work each layers moving each 
// element in the layer with its counterpart in another row or column.
// You can think of it as rotating an array in-place, you divide the array in sets, save the first value
// and start changing the first index with the second, so on and so forth, until you reach the last element, which
// will get the temporary first value we saved. In this case we are changing one element per side of the matrix in each layer
// so the first element will be saved, then overwritten by the first element on the next side, until we reach the last element
// that will be overwritten with the saved value previously in our loop.
void rotateMatrix(vector<vector<int>>& matrix) {
    for (int layer = 0; layer < matrix.size() / 2; layer++) {
        int first = layer;
        int last = matrix.size() - 1 - layer;
        for (int i = first; i < last; i++) {
            int offset = i - first;
            int top = matrix[first][i];

            matrix[first][i] = matrix[last - offset][first];
            matrix[last - offset][first] = matrix[last][last - offset];
            matrix[last][last - offset] = matrix[i][last];
            matrix[i][last] = top;
        }
    }
}

int main() {
    // Read input
    vector<vector<int>> v;
    
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);

        int num;
        vector<int> tmp;
        while (iss >> num) tmp.push_back(num);
        v.push_back(tmp);
    }

    // Write output
    rotateMatrix(v);
    for (auto t : v) {
        for (auto num : t) cout << num << " ";
        cout << endl;
    }
    return 0;
}
