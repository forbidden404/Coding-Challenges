#include <bits/stdc++.h>

using namespace std;

int main() {
    int cases;
    cin >> cases;
	while (cases--) {
        int stores;
        cin >> stores;

        vector<int> arr;
        while (stores--) {
            int store;
            cin >> store;
            arr.push_back(store);
        }
        sort(arr.begin(), arr.end());

        int total = 0;
        for (int i = arr.size() - 1; i >= 1; i--) {
            total += (arr[i] - arr[i-1]);
        }
        total += (arr[arr.size() - 1] - arr[0]);
        cout << total << endl;
	}
	return 0;
}
