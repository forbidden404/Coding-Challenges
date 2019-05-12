#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Using a Hash Set we can tell when we already visited an element in our lists.
ListNode* intersection(ListNode* lhs, ListNode* rhs) {
    unordered_set<ListNode*> visited;

    auto node = lhs;
    while (node != nullptr) {
        visited.insert(node);
        node = node->next;
    }

    node = rhs;
    while (node != nullptr) {
        if (visited.find(node) != visited.end()) return node;
        node = node->next;
    }

    return nullptr;
}

int main() {
    auto cur = new ListNode(0);
    auto lhs = cur;

    for (int i = 1; i < 5; i++) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }

    auto rhs = cur;
    for (int i = 5; i < 10; i++) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }

    auto answer = intersection(lhs, rhs);
    cout << (answer != nullptr ? to_string(answer->val) : "No intersection found.") << endl;

    return 0;
}
