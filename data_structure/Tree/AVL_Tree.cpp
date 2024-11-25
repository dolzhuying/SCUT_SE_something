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
int height(Node *&N) {
    return N==nullptr?0:N->height;
}

// 节点的平衡因子
int getBalanceFactor(Node *&N) {
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

// 更新节点的高度
void updateHeight(Node *&N) {
    N->height = 1 + max(height(N->left), height(N->right));
}

// 右旋
void rightRotate(Node *&y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;
    
    updateHeight(y);
    updateHeight(x);

    y=x;
}

// 左旋
void leftRotate(Node *&x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    x=y;
}

void insert(Node*&root,int data){
    if(!root){
        root=new Node(data);
        return;
    }
    if(data<root->key){
        insert(root->left,data);
    }
    else if(data>root->key){
        insert(root->right,data);
    }
    else{
        return;
    }
    updateHeight(root);
    int balance=getBalanceFactor(root);
    //左左
    if(balance>1&&data<root->left->key){
        rightRotate(root);
    }
    //右右
    else if(balance<-1&&data>root->right->key){
        leftRotate(root);
    }
    //左右
    else if(balance>1&&data>root->left->key){
        leftRotate(root->left);
        rightRotate(root);
    }
    //右左
    else if(balance<-1&&data<root->right->key){
        rightRotate(root->right);
        leftRotate(root);
    }
}

// 最小值节点
Node* getMinValueNode(Node *&node) {
    Node *current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

// 删除节点并保持平衡
// Node* deleteNode(Node *root, int key) {
//     //标准BST删除
//     if (root == nullptr)
//         return root;

//     if (key < root->key)
//         root->left = deleteNode(root->left, key);
//     else if (key > root->key)
//         root->right = deleteNode(root->right, key);
//     else {
//         // 节点只有一个子节点或没有子节点
//         if (root->left == nullptr) {
//             Node *temp = root->right;
//             delete root;
//             return temp;
//         } else if (root->right == nullptr) {
//             Node *temp = root->left;
//             delete root;
//             return temp;
//         }

//         // 节点有两个子节点
//         Node *temp = getMinValueNode(root->right);
//         root->key = temp->key;
//         root->right = deleteNode(root->right, temp->key);
//     }

//     // 如果树只有一个节点，则直接返回
//     if (root == nullptr)
//         return root;

//     updateHeight(root);

//     int balance = getBalanceFactor(root);

//     // 左左
//     if (balance > 1 && getBalanceFactor(root->left) >= 0)
//         return rightRotate(root);

//     // 左右
//     if (balance > 1 && getBalanceFactor(root->left) < 0) {
//         root->left = leftRotate(root->left);
//         return rightRotate(root);
//     }

//     // 右右
//     if (balance < -1 && getBalanceFactor(root->right) <= 0)
//         return leftRotate(root);

//     // 右左
//     if (balance < -1 && getBalanceFactor(root->right) > 0) {
//         root->right = rightRotate(root->right);
//         return leftRotate(root);
//     }

//     // 返回不变的节点指针
//     return root;
// }
void deleteNode(Node*& root, int key) {
    if (root == nullptr)
        return;

    if (key < root->key)
        deleteNode(root->left, key);
    else if (key > root->key)
        deleteNode(root->right, key);
    else {
        // 节点只有一个子节点或没有子节点
        if (root->left == nullptr) {
            Node *temp = root->right;
            delete root;
            root = temp;
            return;
        } else if (root->right == nullptr) {
            Node *temp = root->left;
            delete root;
            root = temp;
            return;
        }

        // 节点有两个子节点
        Node *temp = getMinValueNode(root->right);
        root->key = temp->key;
        deleteNode(root->right, temp->key);
    }

    updateHeight(root);

    int balance = getBalanceFactor(root);

    // 左左
    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        rightRotate(root);

    // 左右
    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        leftRotate(root->left);
        rightRotate(root);
    }

    // 右右
    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        leftRotate(root);

    // 右左
    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        rightRotate(root->right);
        leftRotate(root);
    }
}


