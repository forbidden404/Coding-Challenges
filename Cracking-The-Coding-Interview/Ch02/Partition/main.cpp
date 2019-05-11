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

// In this solution we keep 4 pointers, 2 to keep track of the nodes
// smaller than x, and the other 2 to keep track of the nodes equal or bigger
// than x. Then it is just a matter of moving them around.
void partition(ListNode *root, int x) {
    ListNode* beforeStart   = nullptr;
    ListNode* beforeEnd     = nullptr;
    ListNode* afterStart    = nullptr;
    ListNode* afterEnd      = nullptr;
    auto node = root;

    node = node->next;
    while (node != nullptr) {
        auto next = node->next;
        node->next = nullptr;
        if (node->val < x) {
            if (beforeStart == nullptr) {
                beforeStart = node;
                beforeEnd = beforeStart;
            } else {
                beforeEnd->next = node;
                beforeEnd = node;
            }
        } else {
            if (afterStart == nullptr) {
                afterStart = node;
                afterEnd = afterStart;
            } else {
                afterEnd->next = node;
                afterEnd = node;
            }
        }
        node = next;
    }

    if (beforeStart == nullptr) {
        root->next = afterStart;
    } else {
        beforeEnd->next = afterStart;
        root->next = beforeStart;
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

    // Write output
    partition(list, num);
    printList(list);

    return 0;
}

