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

// This question comes down to the constraints you will put on your own solution. As in,
// will you create a new list that will hold the merged nodes? Will you create a new node
// for each node in this merged list? In my case, I would rather modify both lists and return
// the first list with all the elements merged in a sorted away.
// The algorithm is simple, we traverse both lists at the same time and once we find an element
// in the second list that is bigger than the element in the first list, we insert it before the
// element in the first list. If we processed all elements in the first list and there are still
// elements left in the second one, we just attach the rest of the second list at the end of
// the first one.
ListNode* insertBefore(ListNode* l1, ListNode* l2) {
    auto temp = l1->val;
    auto next = l2->next;

    // Since we want to add l2 before l1, we just 
    // swap their values and set l1 as the next element of l2
    l1->val = l2->val;
    l2->next = l1->next;
    l2->val = temp;
    l1->next = l2;

    return next;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    auto l1_cur = l1;
    auto l2_cur = l2;

    if (!l1_cur) return l2;

    while (l1_cur != nullptr && l2_cur != nullptr) {
        if (l1_cur->val >= l2_cur->val) {
            l2_cur = insertBefore(l1_cur, l2_cur);
        }

        if (l1_cur->next == nullptr && l2_cur != nullptr) {
            l1_cur->next = l2;
            break;
        }

        l1_cur = l1_cur->next;
    }

    return l1;
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
    auto answer = mergeTwoLists(leftList, rightList);
    printList(answer);

    return 0;
}
