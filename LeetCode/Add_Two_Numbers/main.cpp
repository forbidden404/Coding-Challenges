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

int main() {
    // Read input
    string inputLine;
    cin >> inputLine;
    istringstream isl(inputLine);

    vector<int> left;
    char delim;

    int num;
    while (isl >> delim >> num)
        left.push_back(num);

    auto leftList = createListFromVector(left);

    cin >> inputLine;
    istringstream isr(inputLine);

    vector<int> right;
    while (isr >> delim >> num)
        right.push_back(num);

    auto rightList = createListFromVector(right);

    // Write output
    auto answer = addTwoNumbers(leftList, rightList);
    printList(answer);

    return 0;
}
