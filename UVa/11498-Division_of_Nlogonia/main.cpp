#include <bits/stdc++.h>

using namespace std;

int main() {
    int c;
    while (scanf("%d", &c), (c)) {
        int divisionX, divisionY;
        scanf("%d %d", &divisionX, &divisionY);

        while (c--) {
            int x, y;
            scanf("%d %d", &x, &y);
            if (x == divisionX || y == divisionY) {
                cout << "divisa" << endl;
                continue;
            } 

            string answer;
            if (y > divisionY) {
                answer += "N";
            } else {
                answer += "S";
            }

            if (x > divisionX) {
                answer += "E";
            } else {
                answer += "O";
            }

            cout << answer << endl;
        }
    }
	return 0;
}
