#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* createListFromVector(vector<int>& v) {
    if (v.empty()) return nullptr;
    auto cur = new ListNode(v[0]);
    auto root = cur;

    for (int i = 1; i < v.size(); i++) {
        cur->next = new ListNode(v[i]);
        cur = cur->next;
    }

    return root;
}

void printList(ListNode *root) {
    if (root == nullptr) cout << endl;
    cout << "[";

    auto cur = root;
    while (cur->next != nullptr) {
        cout << cur->val << ",";
        cur = cur->next;
    }

    cout << cur->val << "]" << endl;
}

// Solution consists of keeping track of carry and summing the first i-th element of both lists.
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;

    auto cur_1 = l1;
    auto cur_2 = l2;

    // Since the question guarantees there won't be an empty list, we can start by the first digits.
    // This way we can save the head easily.
    auto head = new ListNode((cur_1->val + cur_2->val) % 10);
    if (cur_1->val + cur_2->val >= 10) carry = 1;

    cur_1 = cur_1->next;
    cur_2 = cur_2->next;

    auto cur_3 = head;
    while (cur_1 != nullptr && cur_2 != nullptr) {
        int value = cur_1->val + cur_2->val + carry;
        if (value >= 10) carry = 1;
        else carry = 0;

        cur_3->next = new ListNode(value % 10);
        cur_3 = cur_3->next;

        cur_1 = cur_1->next;
        cur_2 = cur_2->next;
    }

    // After doing the process of adding digit by digit, there might be elements left in l1 or l2 that were not processed if they don't have the same size
    while (cur_1 != nullptr) {
        int value = cur_1->val + carry;
        if (value >= 10) carry = 1;
        else carry = 0;

        cur_3->next = new ListNode(value % 10);
        cur_3 = cur_3->next;

        cur_1 = cur_1->next;
    }

    while (cur_2 != nullptr) {
        int value = cur_2->val + carry;
        if (value >= 10) carry = 1;
        else carry = 0;

        cur_3->next = new ListNode(value % 10);
        cur_3 = cur_3->next;

        cur_2 = cur_2->next;
    }

    // If there's still a number on carry, we need to add a 1 to the end
    if (carry)
        cur_3->next = new ListNode(1);

    return head;
}

// For the follow-up, we could simply reverse our lists, use the previous function
// and then reverse the result, but that would be too easy, so let's try to avoid
// that solution.

// We will create a data structure that will keep the Partial Sum 
struct PartialSum {
    ListNode *sum = nullptr;
    int carry = 0;
};

// We need to check the length of both lists to know if there will be
// need to add any padding to the lists, so they have the same size
int length(ListNode* root) {
    auto node = root;
    int length = 0;
    while (node != nullptr) {
        node = node->next;
        length++;
    }

    return length;
}

ListNode *insertBefore(ListNode* root, int value) {
    auto node = new ListNode(value);
    if (root) {
        node->next = root;
    }
    return node;
}

ListNode* padList(ListNode* root, int padding) {
    for (int i = 0; i < padding; i++) {
        root = insertBefore(root, 0);
    }
    return root;
}

// Now that we have our partial sum and we can add a padding
// to our lists, let's check how we are actually going to
// answer this question.
//
// We will check the partial sum of the next two nodes in
// both of our lists and then add to the nodes we are at,
// saving our answer in our PartialSum object. If you think
// about it, after we made sure our lists have the same length,
// we can recursively ask for the sum of the elements, starting
// from the last one, since our case base is when both are nullptr,
// returning a zero sum, we start building up our PartialSum
// until we have the complete sum.
PartialSum* addTwoNumbersHelper(ListNode* lhs, ListNode* rhs) {
    if (lhs == nullptr && rhs == nullptr) {
        return new PartialSum();
    }

    auto sum = addTwoNumbersHelper(lhs->next, rhs->next);
    int val = sum->carry + lhs->val + rhs->val;

    auto fullResult = insertBefore(sum->sum, val % 10);

    sum->sum = fullResult;
    sum->carry = val / 10;
    return sum;
}

ListNode* addTwoNumbers2(ListNode* lhs, ListNode* rhs) {
    int len1 = length(lhs);
    int len2 = length(rhs);

    // Pad the shorter list
    if (len1 < len2) lhs = padList(lhs, len2 - len1);
    else rhs = padList(rhs, len1 - len2);

    // Start recursively summing our lists;
    auto sum = addTwoNumbersHelper(lhs, rhs);

    ListNode* result = nullptr;
    if (sum->carry == 0) {
        result = sum->sum;
    } else { // Since carry is not 0, there's one element left to be added
        result = insertBefore(sum->sum, sum->carry);
    }

    return result;
}

int main() {
    // Read input
    string inputLine;
    getline(cin, inputLine);
    istringstream iss(inputLine);

    vector<int> left;
    char delim;

    int num;
    while (iss >> delim >> num)
        left.push_back(num);

    auto leftList = createListFromVector(left);

    getline(cin, inputLine);
    iss.str(inputLine);
    iss.clear();

    vector<int> right;
    while (iss >> delim >> num)
        right.push_back(num);

    auto rightList = createListFromVector(right);

    // Write output
    auto answer = addTwoNumbers(leftList, rightList);
    printList(answer);

    // Follow up
    getline(cin, inputLine);
    iss.str(inputLine);
    iss.clear();
    
    left.clear();
    while (iss >> delim >> num)
        left.push_back(num);

    leftList = createListFromVector(left);

    getline(cin, inputLine);
    iss.str(inputLine);
    iss.clear();

    right.clear();
    while (iss >> delim >> num)
        right.push_back(num);

    rightList = createListFromVector(right);

    // Write output
    answer = addTwoNumbers2(leftList, rightList);
    printList(answer);

    return 0;
}

