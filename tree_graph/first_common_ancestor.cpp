// If the node has a parent link, this problem become very similar
// to the linked lists intersection problem.
//
// Without using parent link, we can use this property of binary
// tree: if the two nodes belong to differnt left and right
// subtree, the root node is the common ancestor.
// If the two nodes belong to the same subtree, recurse down
// to that subtree until the two nodes 'split' to two subtrees.

#include <cstdio>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node *parent;
    Node(int v) {
        this->data = v;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
    }
};


void inorder(Node *root) {
    if (!root) return;

    inorder(root->left);

    printf("%d ", root->data);

    inorder(root->right);
}

// left and right are inclusive indices to the array a
Node *buildBstUtil(int a[], Node* parent, int left, int right) {
    if (left > right)
        return nullptr;

    int mid = (left + right) / 2;
    Node *node = new Node(a[mid]);
    node->parent = parent;
    node->left = buildBstUtil(a, node, left, mid - 1);
    node->right = buildBstUtil(a, node, mid + 1, right);

    return node;
}

Node *buildBst(int a[], int n) {
    return buildBstUtil(a, nullptr, 0, n - 1);
}

bool nodeInTree(Node *root, Node *n) {
    if (!root) return false;
    if (root == n) return true;

    return nodeInTree(root->left, n) || nodeInTree(root->right, n);
}

Node *commonAncestor(Node *root, Node *p, Node *q) {
    if (!root) return nullptr;

    if (root == p || root == q) return root;

    bool pInLeftTree = nodeInTree(root->left, p);
    bool qInLeftTree = nodeInTree(root->left, q);

    if (pInLeftTree != qInLeftTree) // p & q belong to different subtree
        return root;

    if (pInLeftTree) { // p & q are both in the left subtree
        return commonAncestor(root->left, p, q);
    }

    return commonAncestor(root->right, p, q);
}

int main() {
#define LIM 7
    int a[LIM] = {6, 2, 7, 4, 1, 5, 3};
    std::sort(a, a + LIM);  // sort to make BST
                            // else it would be just a binary tree
    Node *root = buildBst(a, LIM);

    Node *common = commonAncestor(root, root->left->left, root->left->right);

    printf("Common ancestor: %d\n", common->data);

    return 0;
}
