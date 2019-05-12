#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    for (; a <= b; a++) {
        if (a > 9) {
            cout << (a % 2 == 0 ? "even" : "odd") << endl;
        } else {
            switch (a) {
                case 1:
                    cout << "one" << endl;
                    break;
                case 2:
                    cout << "two" << endl;
                    break;
                case 3:
                    cout << "three" << endl;
                    break;
                case 4:
                    cout << "four" << endl;
                    break;
                case 5:
                    cout << "five" << endl;
                    break;
                case 6:
                    cout << "six" << endl;
                    break;
                case 7:
                    cout << "seven" << endl;
                    break;
                case 8:
                    cout << "eight" << endl;
                    break;
                case 9:
                    cout << "nine" << endl;
                    break;
                default:
                    cout << "Greater than 9" << endl;
            }
        }
    }

    return 0;
}


