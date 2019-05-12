#include <bits/stdc++.h>
using namespace std;

void quickSort(vector<int> &arr) {
    if (arr.size() < 2) { return; }

    vector<int> left;
    vector<int> right;

    int value = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > value) {
            right.push_back(arr[i]);
        } else {
            left.push_back(arr[i]);
        }
    }
    quickSort(left);
    quickSort(right);

    int i = 0;
    for (int j = 0; j < left.size(); j++) {
        arr[i++] = left[j];
        printf("%d ", left[j]);
    }

    arr[i++] = value;
    printf("%d ", value);

    for (int j = 0; j < right.size(); j++) {
        printf("%d ", right[j]);
        arr[i++] = right[j];
    }

    printf("\n");
}

int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr);

    return 0;
}


