#include <bits/stdc++.h>

using namespace std;

void printVector(vector<string>& v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1)
            cout << ",";
    }
    cout << "]\n";
}

// We are adding all the valid sequences of size c inside another valid sequence, plus valid
// sequences of size  n - 1 c, while saving repeated answers in a Hash Table. If we know that 
// the first and last elements are valid, then all the elements in between have to be a valid 
// sequence too, plus the rest of the elements. So we consider ( l ), where ( and ) are the 
// first and last elements that are valid, with l being all the other sequences that have to 
// be valid too, plus all the other valid subsequences that are not part of the first sequence. 
// That's why we have ( + l + ) + r
unordered_map<int, vector<string>> cache;
vector<string> generateParenthesis(int n) {
    vector<string> answer;
    if (cache.find(n) != cache.end()) return cache[n];
    if (n == 0) answer.push_back("");
    else {
        for (int c = n - 1; c >= 0; c--)
            for (auto left : generateParenthesis(c))
                for (auto right : generateParenthesis(n - 1 - c))
                    answer.push_back("(" + left + ")" + right);
    }
    return cache[n] = answer;
}

int main() {
    // Read input
    int n;
    cin >> n;

    // Write output
    auto answer = generateParenthesis(n);
    printVector(answer);

    return 0;
}
