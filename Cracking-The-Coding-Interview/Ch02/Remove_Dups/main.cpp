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

// Using a Hash Set we can keep track of the nodes 
// that we have seen already and we can remove them 
// from the actual list.
ListNode* removeDups(ListNode *root) {
    if (root == nullptr) return nullptr;

    auto node = root;
    unordered_set<int> seen;

    seen.insert(root->val);
    while (node->next != nullptr) {
        if (seen.find(node->next->val) != seen.end()) {
            // remove node by bypassing the deleted node
            auto tmp = node->next;
            auto next = node->next->next;
            node->next = next;
            delete tmp;
            continue; // restart loop so node isn't updated twice
        } else {
            seen.insert(node->next->val);
        }

        node = node->next;
    }

    return root;
}

// Without using a temporary buffer, we can use two pointers
// to delete duplicates. We will have a pointer keeping actual node
// and another pointer that will look in the list for duplicates
// and delete them before updating the first pointer.
ListNode* removeDupsNoBuffer(ListNode *root) {
    if (root == nullptr) return nullptr;

    auto first = root;
    auto second = root;

    while (first != nullptr) {
        while (second->next != nullptr) {
            if (second->next->val == first->val) {
                auto tmp = second->next;
                auto next = second->next->next;
                second->next = next;
                delete tmp;
                continue;
            }
            second = second->next;
        }

        first = first->next;
        second = first;
    }

    return root;
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

    // Write output
    auto answer = removeDupsNoBuffer(list);
    printList(answer);

    return 0;
}

