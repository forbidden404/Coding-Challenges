#include <bits/stdc++.h>

using namespace std;

// This solution requires a lot of details to fully grasp the concepts involved, so I would recommend to check the solution tab in LeetCode for this question.
// What I can say is that the median is a number that divides an array in two parts of the same size where each element on the left part is smaller than the ones on the right.
// If we think of ways to divide nums1 and nums2 with i and j elements respectively, in such a way that i + j will count for half of the combined size of them,
// if you guarantee that A[i] and B[j] are the biggest numbers combining A[0..i] and B[0..j], you have found the middle numbers of this combined array
// and now you just have to check if the combined size is odd or not so you can use the formula for the median.
// We are using binary search to set our i and setting our j based on our i such as j = (m + n + 1)/2 - i, so i + j is half of the size and we check if we found
// an i and j that satisfy A[i] > B[j - 1] and B[j] > A[i - 1].
double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
    int m = nums1.size();
    int n = nums2.size();

    if (m > n) return findMedianSortedArrays(nums2, nums1);

    int iMin = 0, iMax = m, halfLength = (m + n + 1) / 2;
    while (iMin <= iMax) { // Binary search for i
        int i = (iMin + iMax) / 2;
        int j = halfLength - i;
        if (i < iMax && nums2[j - 1] > nums1[i]) // if A[i] < B[j - 1], we increase our iMin so A[i] increases too 
            iMin = i + 1;
        else if (i > iMin && nums1[i - 1] > nums2[j]) // if B[j] < A[i - 1], we decrease our iMax so A[i] decreases too
            iMax = i - 1;
        else {                                              // Now A[i] > B[j - 1] and B[j] > A[i - 1] is true
            int maxLeft = 0;
            if (i == 0) maxLeft = nums2[j - 1];             // These two lines below are used to avoid getting negative indexes
            else if (j == 0) maxLeft = nums1[i - 1];
            else maxLeft = max(nums2[j - 1], nums1[i - 1]); // This is the actual line for our concept, if you think of our combined array, this would be picking the middle - 1 element
            if ((m + n) % 2 == 1) return maxLeft;

            int minRight = 0;
            if (i == m) minRight = nums2[j];                // These two lines below are used to avoid getting indexes bigger than the allowed size
            else if (j == n) minRight = nums1[i];
            else minRight = min(nums1[i], nums2[j]);        // This is the actual line for our concept, if you think of our combined array, this would be picking the middle + 1 element
            return (maxLeft + minRight) / 2.0;
        }
    }

    return 0.0;
}

int main() {
    // Read input
    string inputLine;
    getline(cin, inputLine);
    istringstream isl(inputLine);

    vector<int> left;
    char delim;

    int num;
    while (isl >> delim >> num)
        left.push_back(num);

    getline(cin, inputLine);
    istringstream isr(inputLine);

    vector<int> right;
    while (isr >> delim >> num)
        right.push_back(num);

    // Write output
    cout << findMedianSortedArrays(left, right) << endl;

    return 0;
}

