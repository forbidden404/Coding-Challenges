#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void printVector(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (i != 0) cout << ' ';
        cout << arr[i];
    }
    cout << endl;
}

int partition(vector<int> &arr, int left, int right) {
    int value = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] <= value) {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[right]);
    printVector(arr);
    return i + 1;
}

void quickSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int q = partition(arr, left, right);
        quickSort(arr, left, q - 1);
        quickSort(arr, q + 1, right);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++) { 
        cin >> arr[i];
    }

    quickSort(arr, 0, arr.size() - 1);

    return 0;
}

