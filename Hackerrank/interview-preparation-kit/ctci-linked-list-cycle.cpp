/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

struct Node {
    int data;
    struct Node* next;
};

bool has_cycle(Node* head) {
    if (head == nullptr || head->next == nullptr) { return false; }
    Node* visited[101]; // unordered_set would be better
    int index = 0;
    
    auto cur = head;
    while (cur != nullptr) {
        for (int i = 0; i < index; i++) {
            if (cur == visited[i]) { return true; }
        }
        
        visited[index++] = cur;
        cur = cur->next;
    }
    
    return false;
}
