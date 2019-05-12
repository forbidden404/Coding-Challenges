#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int c; 
    scanf("%d", &c);

    int arr[c];
    for (int i = c - 1; i >= 0; i--) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < c; i++) {
        printf("%d", arr[i]);
        if (i != c - 1) printf(" ");
    }

    return 0;
}

