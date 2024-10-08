#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
    Node *parent;

    Node(int d) : key(d), left(nullptr), right(nullptr), parent(nullptr) {}
};

// 伸展
void splay(Node *node) {
    while (node->parent != nullptr) {
        Node *parent = node->parent;
        Node *grandparent = parent->parent;

        // Zig Zig 
        if (grandparent != nullptr) {
            if ((node == parent->left) && (parent == grandparent->left)) {
                // 先右旋父节点，再右旋节点本身
                parent = rightRotate(parent);
                splay(node);
            } else if ((node == parent->right) && (parent == grandparent->right)) {
                // 先左旋父节点，再左旋节点本身
                parent = leftRotate(parent);
                splay(node);
            }
        }

        // Zig Zag 情况
        if (grandparent != nullptr) {
            if ((node == parent->right) && (parent == grandparent->left)) {
                // 先左旋节点，再右旋父节点
                node = leftRotate(node);
                splay(node);
            } else if ((node == parent->left) && (parent == grandparent->right)) {
                // 先右旋节点，再左旋父节点
                node = rightRotate(node);
                splay(node);
            }
        }

        // Zig 情况
        if (parent != nullptr) {
            if (node == parent->left) {
                parent = rightRotate(parent);
            } else if (node == parent->right) {
                parent = leftRotate(parent);
            }
        }
    }
}

// 右旋
Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    // 更新父节点关系
    if (T2 != nullptr)
        T2->parent = y;
    y->parent = x;

    // 如果 y 的父节点不为空，更新父节点关系
    if (y->parent != nullptr) {
        if (y->parent->left == y)
            y->parent->left = x;
        else
            y->parent->right = x;
    }

    // 更新 x 的父节点
    x->parent = y->parent;
    y->parent = x;

    return x;
}

// 左旋
Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    // 更新父节点关系
    if (T2 != nullptr)
        T2->parent = x;
    x->parent = y;

    // 如果 y 的父节点不为空，更新父节点关系
    if (y->parent != nullptr) {
        if (y->parent->left == x)
            y->parent->left = y;
        else
            y->parent->right = y;
    }

    // 更新 y 的父节点
    y->parent = x->parent;
    x->parent = y;

    return y;
}

// 查找节点
Node* find(Node *root, int key) {
    Node *current = root;
    while (current != nullptr) {
        if (key == current->key)
            break;
        if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }
    if (current != nullptr)
        splay(current); // 将找到的节点移动到根部
    return current;
}

// 插入节点
Node* insert(Node *root, int key) {
    if (root == nullptr)
        return new Node(key);

    Node *current = root;
    Node *parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (key < current->key)
            current = current->left;
        else if (key > current->key)
            current = current->right;
        else
            return root; // 键值已存在
    }

    // 创建新节点并插入
    Node *newNode = new Node(key);
    newNode->parent = parent;

    if (key < parent->key)
        parent->left = newNode;
    else
        parent->right = newNode;

    splay(newNode); // 将新节点移动到根部
    return newNode;
}

// 删除节点
Node* deleteNode(Node *root, int key) {
    Node *target = find(root, key);
    if (target == nullptr)
        return root;

    splay(target); // 将目标节点移动到根部

    // 分离左右子树
    Node *leftSubtree = target->left;
    Node *rightSubtree = target->right;

    // 删除根节点
    delete target;
    target = nullptr;

    // 合并左右子树
    if (leftSubtree == nullptr)
        return rightSubtree;

    Node *current = leftSubtree;
    while (current->right != nullptr)
        current = current->right;

    current->right = rightSubtree;
    if (rightSubtree != nullptr)
        rightSubtree->parent = current;

    return leftSubtree;
}