#include <bits/stdc++.h>

using namespace std;

// We can check every pair of possible limiters and calculate its area, but
// that would be O(n^2). There is a better way to answer this question in
// O(n). Think of what we are trying to accomplish based on our constraints,
// every time we move our leftmost bar to the right or our rightmost bar to the left,
// we are decreasing our width. Our height will always be bound to the minimum height
// between both bars, so the only thing we can optimize while decreasing the width is
// to move the smallest bar hoping that the increase of height will improve our area
// enough even with the decreased width. 
// So to answer this, we start with the biggest container possible and calculate its area,
// then we just need to move the smallest bar and check its area until we get to the last
// pair of bars.
int maxArea(vector<int>& heights) {
    int left = 0;
    int right = heights.size() - 1;
    int maxArea = 0;

    while (left < right) {
        int width = right - left;
        int height = min(heights[left], heights[right]);
        int area = width * height;
        maxArea = max(maxArea, area);
        if (heights[left] > heights[right]) {
            right--;
        } else {
            left++;
        }
    }

    return maxArea;
}

int main() {
    // Read input
    string inputLine;
    cin >> inputLine;
    istringstream isl(inputLine);

    vector<int> heights;
    char delim;

    int num;
    while (isl >> delim >> num)
        heights.push_back(num);

    // Write output
    cout << maxArea(heights) << endl;

    return 0;
}

