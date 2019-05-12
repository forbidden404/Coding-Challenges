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

// Trivial solution is to use a hash set and check if we already saw that node
ListNode* loopDetection(ListNode *root) {
    unordered_set<ListNode*> visited;

    auto node = root;
    while (node != nullptr) {
        if (visited.find(node) != visited.end()) return node;
        visited.insert(node);
        node = node->next;
    }

    return nullptr;
}

// If we don't want to use a hash set, we can use two pointers and move 
// one of them two nodes at a time, once they collide, we move the slow
// pointer to the beginning of our list and start walking with both one step
// at the time, when they collide again, that will be the intersection.
// This works because when the slow pointer enters the loop, after k nodes,
// the fast pointer is k nodes into the loop, this means slow and fast are
// LOOP_SIZE - k nodes away from each other. Since it took k nodes for slow to
// get into the loop, then the root of our list is k nodes from the loop too,
// so we just need to readjust our slow pointer and now move both at the same
// pace so we can reach the cycle point.
ListNode* hasCycle(ListNode *root) {
    auto slow = root;
    auto fast = root;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break; // Collision
    }

    if (fast == nullptr || fast->next == nullptr) return nullptr; // No loop

    slow = root;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return fast;
}

int main() {
    vector<int> v{3, 2, 0, 4};

    auto lhs = createListFromVector(v);

    // Add loop
    auto cur = lhs;
    while (cur->next != nullptr) {
        cur = cur->next; 
    }
    cur->next = lhs->next;

    auto answer = hasCycle(lhs);
    cout << (answer != nullptr ? to_string(answer->val) : "No loop detected.") << endl;

    return 0;
}
