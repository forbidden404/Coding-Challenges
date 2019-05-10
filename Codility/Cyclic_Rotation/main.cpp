#include <bits/stdc++.h>

using namespace std;

// This solution is quite simple, but it uses auxiliary space. We just calculate the new index based on the rotation and assign that value from A into that specific index in answer
vector<int> solution(vector<int>& A, int K) {
    vector<int> answer(A.size());

    for (int i = 0; i < A.size(); i++) {
        int index = (i + K) % A.size();
        answer[index] = A[i];
    }

    return answer;
}

// There is another way to do this by doing everything in-place, but it's relatively complicated.
// We can use a juggling algorithm that will move the values based on sets that are the size of gcd between the size of the array and the rotation value
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

vector<int> solution2(vector<int>& A, int K) {
    // We also have to take care of some special cases, which boil down to the same thing, when the array doesn't need a rotation.
    if (A.size() < 2) return A;
    K = K % A.size();
    if (K == 0) return A;

    for (int i = 0; i < gcd(K, A.size()); i++) {
        int temp = A[i];
        int j = i;

        while (true) {
            int k = (j - K);
            if (k < 0) k = A.size() + k;
            if (k == i) break;
            A[j] = A[k];
            j = k;
        }

        A[j] = temp;
    }

    return A;
}

int main() {
    // Read input
    vector<vector<int>> v;
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);

        vector<int> a;
        int num;
        while (iss >> num) 
            a.push_back(num);
        v.push_back(a);
    }

    // Write output
    vector<vector<int>> answer;
    for_each(v.begin(), v.end(), [&answer](vector<int>& a) { int k = a[a.size() - 1]; a.pop_back(); answer.push_back(solution2(a, k)); }); 

    for (auto vec : answer) {
        cout << "[";
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i];
            if (i != vec.size() - 1)
                cout << ", ";
        }
        cout << "]\n";
    }
    return 0;
}
