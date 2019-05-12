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

int length(ListNode* root) {
    auto node = root;
    int i = 0;
    while (node != nullptr) {
        node = node->next;
        i++;
    }
    return i;
}

ListNode* kthToLastIterative(ListNode *root, int k) {
    auto first = root;
    auto second = root;

    for (int i = 0; i < k; i++) {
        if (second == nullptr) return nullptr;
        second = second->next;
    }

    while (second != nullptr) {
        second = second->next;
        first = first->next;
    }

    return first;
}

// The trivial solution is to check the kthToLast element as
// we did in a previous question and check if the values match.
// Notice that this question has time complexity of O(N^2), which
// is not good enough.
bool isPalindrome(ListNode* root) {
    int limit = length(root) / 2;

    auto node = root;
    for (int i = 1; i <= limit; i++) {
        if (node->val != (kthToLastIterative(root, i)->val)) return false;
        node = node->next;
    }

    return true;
}

// There is a better way to do this if we can use additional space.
// We can reverse the list and save this in another one, then we can
// check if both lists are equal, if they are, it's a palindrome.
ListNode* reverseAndClone(ListNode* root) {
    ListNode* head = nullptr;
    while (root != nullptr) {
        auto node = new ListNode(root->val);
        node->next = head;
        head = node;
        root = root->next;
    }
    return head;
}

bool isEqual(ListNode* lhs, ListNode* rhs) {
    while (lhs != nullptr && rhs != nullptr) {
        if (lhs->val != rhs->val) return false;
        lhs = lhs->next;
        rhs = rhs->next;
    }

    return lhs == nullptr && rhs == nullptr;
}

bool isPalindromeAux(ListNode *root) {
    auto reversed = reverseAndClone(root);
    return isEqual(root, reversed);
}

int main() {
    // Read input
    string inputLine;
    while (getline(cin, inputLine)) {
        istringstream isl(inputLine);

        vector<int> v;
        char delim;

        int num;
        while (isl >> delim >> num)
            v.push_back(num);

        auto list = createListFromVector(v);

        // Write output
        cout << (isPalindromeAux(list) ? "true" : "false") << endl;
    }

    return 0;
}

