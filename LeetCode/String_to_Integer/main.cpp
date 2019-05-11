#include <bits/stdc++.h>

using namespace std;

// For this question we just need to structure our thought process
// step by step with the requirements of the number reading.
// If there are any whitespaces in the beginning of the string, we ignore it.
// The next character that can be present in the string and it's not a digit
// can only be the plus or minus sign, so we take that into consideration.
// Then we just need to check for the next digit, you can see that if the next
// character is not a digit, our while loop will be skipped and we will return
// 0 as it was asked in the question. Then we read digit by digit and add that to
// our result, also considering overflow.
int myAtoi(string str) {
    // Remove whitespaces
    auto it = str.begin();
    while (*it == ' ') it++;

    // Read plus/minus sign
    int sign = 1;
    if (*it == '-') {
        sign = -1;
        it++;
    } else if (*it == '+')
        it++;

    int result = 0;

    // Read numbers
    while (*it >= '0' && *it <= '9') {
        int digit = *it++ - '0';
        if ((INT_MAX - digit)/10 < result)
            return sign == 1 ? INT_MAX : INT_MIN;
        result = result * 10 + digit;
    }

    return result * sign;
}

int main() {
    string line;
    while (getline(cin, line)) {
        cout << myAtoi(line) << endl;
    }

    return 0;
}
