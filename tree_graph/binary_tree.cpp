#include <cstdio>
#include <algorithm>

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int v) {
        this->data = v;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void inorder(Node *root) {
    if (!root) return;

    inorder(root->left);
    
    printf("%d ", root->data);

    inorder(root->right);
}

// left and right are inclusive indices to the array a
Node *buildBstUtil(int a[], int left, int right) {
    if (left > right)
        return nullptr;

    int mid = (left + right) / 2;
    Node *node = new Node(a[mid]);
    node->left = buildBstUtil(a, left, mid - 1);
    node->right = buildBstUtil(a, mid + 1, right);

    return node;
}

Node *buildBst(int a[], int n) {
    return buildBstUtil(a, 0, n - 1);
}

int main() {
#define LIM 9
    int a[9] = {6, 2, 7, 4, 8, 9, 1, 5, 3};
    std::sort(a, a + LIM);  // sort to make BST
                            // else it would be just a binary tree
    Node *root = buildBst(a, LIM);
    
    inorder(root);
    printf("\n");

    return 0;
}
