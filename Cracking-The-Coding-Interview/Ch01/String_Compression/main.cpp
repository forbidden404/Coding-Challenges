#include <bits/stdc++.h>

using namespace std;

// For this solution, we are saving which character we have read previously and keeping count 
// of how many we have read so far in a sequence.
// Once the character changes, we add the previous character and its counter to the string.
// In the end we just check if the new string is smaller than the original one and return accordingly.
string stringCompression(string str) {
    if (str.empty()) return str;
    string answer;
    
    char currentChar = str[0];
    int currentCount = 1;
    for (int i = 1; i < str.size(); i++) {
        char c = str[i];
        if (c == currentChar) currentCount++;
        else {
            answer += currentChar;
            answer += to_string(currentCount);
            currentChar = c;
            currentCount = 1;
        }
    }

    answer += currentChar;
    answer += to_string(currentCount);

    return str.size() > answer.size() ? answer : str;
}

int main() {
    // Read input
    string input;
    cin >> input;

    // Write output
    cout << stringCompression(input) << endl;
    return 0;
}
