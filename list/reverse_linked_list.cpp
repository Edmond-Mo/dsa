#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node (int n) {
        this->data = n;
        this->next = nullptr;
    }
};

Node *reverse(Node *node, Node **newHead) {
    if (!node) return nullptr;
    
    Node *n = reverse(node->next, newHead);
    if (n) {
        n->next = node;
        node->next = nullptr;
    }
    else {
        // node is last node
        *newHead = node;
    }
    return node;
}

int main() {
    Node a(1);
    Node b(2);
    Node c(3);
    Node d(4);
    Node e(5);
    
    a.next = &b;
    //b.next = nullptr; 
    b.next = &c;
    c.next = &d;
    d.next = &e;
    
    Node *head = &a;
    cout << "Before:\n";
    while (head) {
        cout << head->data << "\n";
        head = head->next;
    }
    reverse(&a, &head);
    
    cout << "After:\n";
    while (head) {
        cout << head->data << "\n";
        head = head->next;
    }

    return 0;
}
