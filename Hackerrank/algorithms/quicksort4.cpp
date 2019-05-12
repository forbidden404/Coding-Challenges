#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int insertSort(vector<int> &arr) {
    int swaps = 0;
    for (int j = 1; j < arr.size(); j++) {
        int key = arr[j];
        int i = j - 1;
        for (; i >= 0 && arr[i] > key; i--) {
            arr[i + 1] = arr[i];
            swaps++;
        }
        arr[i + 1] = key;
    }
    return swaps;
}

int partition(vector<int> &arr, int left, int right, int *count) {
    int value = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] <= value) {
            i++;
            swap(arr[j], arr[i]);
            *count = *count + 1;
        }
    }
    swap(arr[i + 1], arr[right]);
    *count = *count + 1;
    return i + 1;
}

void quickSort(vector<int> &arr, int left, int right, int *count) {
    if (left < right) {
        int q = partition(arr, left, right, count);
        quickSort(arr, left, q - 1, count);
        quickSort(arr, q + 1, right, count);
    }
}

int countDifference(vector<int> &arr) {
    vector<int> ins(arr.begin(), arr.end());
    int counting = insertSort(ins);

    int quick = 0;
    quickSort(arr, 0, arr.size() - 1, &quick);

    return counting - quick;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << countDifference(arr) << endl;

    return 0;
}

