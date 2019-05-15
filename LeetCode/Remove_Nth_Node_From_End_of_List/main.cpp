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

// This question is simple if you are used to dealing with Linked Lists. As it was shown in
// the CTCI folder Ch01, to find the nth element from the end, we can use use two pointers
// and traverse n nodes with our second pointer. Then we start moving both pointers and when
// the second one reaches the end, the first one, which started n nodes before the second one,
// will be in the nth from the end. Since we need to know the previous element since we don't
// want to change the nodes, just their position, we keep track of the previous element of the
// first pointer. At the end we just need to take care of some special cases.
ListNode* removeNthFromEnd(ListNode* head, int n) {
    auto first = head;
    auto second = head;

    for (int i = 0; i < n; i++) {
        if (second == nullptr) return nullptr;
        second = second->next;
    }

    ListNode* prev = nullptr;
    while (second != nullptr) {
        second = second->next;
        prev = first;
        first = first->next;
    }

    if (prev == nullptr && first->next == nullptr) return nullptr;  // There's only one element
    else if (prev == nullptr) return first->next;                   // Removing the first node.
    else if (first->next == nullptr) prev->next = nullptr;          // Removing the tail node.
    else prev->next = first->next;                                  // Normal deletion.

    return head;
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
    int n;
    cin >> n;

    // Write output
    auto answer = removeNthFromEnd(list, n);
    printList(answer);

    return 0;
}
