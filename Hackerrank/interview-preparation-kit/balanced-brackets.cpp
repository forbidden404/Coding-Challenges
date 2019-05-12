#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    int a = 0;
    int b = 0;
    int c = 0;

    stack<char> lastOpen;
    for (auto d : s) {
        if (d == '(') {
            lastOpen.push(d);
            a++;
        } else if (d == ')') {
            if (lastOpen.empty() || lastOpen.top() != '(')
                return "NO";
            lastOpen.pop();
            a--;
        } else if (d == '[') {
            lastOpen.push(d);
            b++;
        } else if (d == ']') {
            if (lastOpen.empty() || lastOpen.top() != '[')
                return "NO";
            lastOpen.pop();
            b--;
        } else if (d == '{') {
            lastOpen.push(d);
            c++;
        } else if (d == '}') {
            if (lastOpen.empty() || lastOpen.top() != '{')
                return "NO";
            lastOpen.pop();
            c--;
        }
    }

    return ((!a && !b) && !c) ? "YES" : "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

