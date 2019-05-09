#include <bits/stdc++.h>

using namespace std;

// Solution uses a hash table to keep track of the complement of the target and a number in the vector
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> complement;
    for (int i = 0; i < nums.size(); i++) {
        const bool is_in = complement.find(target - nums[i]) != complement.end();
        // Consider A + B = T, and A is the number we are reading right now. A + B = T => B = T - A, so if we check in our hashMap
        // the existence of T - A, then there is a B in our vector and it is the solution
        if (is_in) 
            return {complement[target - nums[i]], i};
        complement[nums[i]] = i;
    }

    return {};
}

int main() {
    // Read input
    vector<int> v;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));

    // Write output
    int target = v[v.size() - 1];
    v.pop_back();

    auto answer = twoSum(v, target);
    cout << "[" << answer[0] << ", " << answer[1] << "]" << endl;

    return 0;
}
