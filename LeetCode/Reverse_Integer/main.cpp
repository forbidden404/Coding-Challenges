#include <bits/stdc++.h>

using namespace std;

// In this question we just need to be careful with integer overflow.
// We just need to take the last digit of x, and add that to answer * 10,
// while always dividing x by 10 so we can get the nest last digit.
// For the overflow, since we are always multiplying by 10, we need to check
// if answer would overflow before our next multiplication step, and to do 
// that we just need to check if it's bigger than INT_MAX/10, or if it's equal
// and the last digit is bigger than 7, that means answer * 10 + pop could be 
// bigger than INT_MAX, the same goes for INT_MIN.
int reverseInteger(int x) {
    int answer = 0;

    while (x != 0) {
        int pop = x % 10;
        x /= 10;

        // Check for overflow
        if (answer > INT_MAX/10 || (answer == INT_MAX/10 && pop > 7)) return 0;
        if (answer < INT_MIN/10 || (answer == INT_MIN/10 && pop < -8)) return 0;

        answer = answer * 10 + pop;
    }

    return answer;
}

int main() {
    int num;
    while (cin >> num) {
        cout << reverseInteger(num) << endl;
    }

    return 0;
}
