#include <bits/stdc++.h>

using namespace std;

// Insertion and Deletion can be treated as the same operation if we switch the function input
bool oneInsert(string str1, string str2) {
    int index1 = 0;
    int index2 = 0;

    while (index1 < str1.size() && index2 < str2.size()) {
        if (str1[index1] != str2[index2]) {
            if (index1 != index2) return false; // More than one addition
            index2++;
        } else {
            index1++;
            index2++;
        }
    }

    return true;
}

bool oneAway(string str1, string str2) {
    // Check for one change
    if (str1.size() == str2.size()) {
        bool diff = false;
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] != str2[i]) {
                if (diff) return false; // More than one change
                diff = true;
            }
        }
        return true; // Zero edit
    }
    // Check for insertion
    else if (str1.size() + 1 == str2.size()) {
        return oneInsert(str1, str2);
    }
    // Check for deletion
    else if (str1.size() - 1 == str2.size()) {
        return oneInsert(str2, str1);
    }
    return false;
}

int main() {
    // Read input and write output
    string left, right;
    while (cin >> left >> right) {
        cout << left << " and " << right << " are " << (oneAway(left, right) ? "" : "not ") << "one (or zero) edit away." << endl; 
    }

    return 0;
}
