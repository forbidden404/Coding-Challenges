// Given an array of integers, find the largest continuous sum
#include <bits/stdc++.h>

using namespace std;

int largestContinuousSum(vector<int>& v) {
    if (v.empty()) return 0;
    
    int currentSum;
    int maxSum = currentSum = v[0];

    for (int i = 1; i < v.size(); i++) {
        int num = v[i];
        currentSum = max(currentSum+num, num);
        maxSum = max(currentSum, maxSum);
    }
    return maxSum;
}

int main() {
    vector<int> v{-40,1,40,-50,1,50,-20,1,20,0,0};
    cout << largestContinuousSum(v) << endl;
    return 0;
}

