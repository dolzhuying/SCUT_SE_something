#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int d) : key(d), left(nullptr), right(nullptr), height(1) {}
};

// 节点的高度
int height(Node *N) {
    if (N == nullptr)
        return 0;
    return N->height;
}

// 节点的平衡因子
int getBalanceFactor(Node *N) {
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

// 更新节点的高度
void updateHeight(Node *N) {
    N->height = 1 + max(height(N->left), height(N->right));
}

// 右旋
Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;
    
    updateHeight(y);
    updateHeight(x);
    // 返回新的根节点
    return x;
}

// 左旋
Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    // 返回新的根节点
    return y;
}

// 插入节点并保持平衡
Node* insert(Node* node, int key) {
    //正常的二叉搜索树插入
    if (node == nullptr)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // 不允许重复键值
        return node;

    updateHeight(node);

    int balance = getBalanceFactor(node);

    // 左左
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // 右右
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // 左右
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // 右左
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    // 返回不变的节点指针
    return node;
}

// 最小值节点
Node* getMinValueNode(Node *node) {
    Node *current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

// 删除节点并保持平衡
Node* deleteNode(Node *root, int key) {
    //标准BST删除
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // 节点只有一个子节点或没有子节点
        if (root->left == nullptr) {
            Node *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // 节点有两个子节点
        Node *temp = getMinValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    // 如果树只有一个节点，则直接返回
    if (root == nullptr)
        return root;

    updateHeight(root);

    int balance = getBalanceFactor(root);

    // 左左
    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    // 左右
    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // 右右
    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);

    // 右左
    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // 返回不变的节点指针
    return root;
}

