#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function
    int val_a = *a;
    int val_b = *b;
    *a = val_a + val_b;
    *b = val_a - val_b;
    if (*b < 0) *b *= -1;  
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

