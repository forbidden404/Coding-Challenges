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

ListNode* kthNode(ListNode *root, int k) {
    if (root == nullptr) return nullptr;

    auto cur = root;
    for (int i = 0; i < (k - 1); i++) {
        if (cur == nullptr) return nullptr;
        cur = cur->next;
    }

    return cur;
}

// If we only have access to that node, we can check if it's the last node.
// If it is, then we just need to set it to null and it should be fine.
// If not, we can update its value to the value of its successor and then
// "delete" the next node, bypassing it.
void deleteMiddleNode(ListNode *node) {
    if (node == nullptr) return;
    if (node->next == nullptr)
        node = nullptr;
    else {
        auto next = node->next;
        node->val = next->val;
        node->next = next->next;
        next = nullptr;
    }
}

int main() {
    // Read input
    string inputLine;
    cin >> inputLine;
    istringstream isl(inputLine);

    vector<int> v;
    char delim;

    int num;
    while (isl >> delim >> num)
        v.push_back(num);

    auto list = createListFromVector(v);
    cin >> num;
    auto node = kthNode(list, num);

    // Write output
    deleteMiddleNode(node);
    printList(list);

    return 0;
}

