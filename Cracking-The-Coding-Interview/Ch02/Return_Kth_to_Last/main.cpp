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

// This question is quite interesting since there are several ways you can
// solve this. First approach will be recursive without using additional 
// variables to keep state in between functions.
int kthToLastRecursive(ListNode* root, int k) {
    if (root == nullptr) return 0;
    int index = kthToLastRecursive(root->next, k) + 1;
    if (index == k) {
        cout << root->val << endl;
    }

    return index;
}

// In this version we can send a variable to keep track of the index
// and that makes it easier to return the kth node too
ListNode* kthToLast(ListNode* root, int k, int &i) {
    if (root == nullptr) return nullptr;
    
    auto head = root;
    auto node = kthToLast(head->next, k, i);
    i++;
    if (i == k) 
        return head;
    return node;
}

ListNode* kthToLast(ListNode* root, int k) {
    int i = 0;
    return kthToLast(root, k, i);
}

// For the iterative version, we just need to keep track of two
// pointers, the first one will advance k nodes ahead of the first.
// That way, we can start moving both and when the second one hits the
// end, the first one will be k nodes before the last.
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
    int k;
    cin >> k;

    // Write output
    auto answer = kthToLast(list, k);
    cout << answer->val << endl;

    return 0;
}

