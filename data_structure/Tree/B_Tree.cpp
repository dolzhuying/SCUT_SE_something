#include <iostream>
#include <vector>

using namespace std;

// 定义 B 树节点
struct Node {
    vector<int> keys;
    vector<Node*> children;
    bool isLeaf;
    int t;

    Node(int _t, bool _isLeaf) : t(_t), isLeaf(_isLeaf) {}

    void splitChild(int i, Node* y);
    void insertNonFull(int k);
    void insertNonFull(int k, int index);
    void insertNonFull(int k, int index, int& newIndex);
    void insertNonFull(int k, int index, int& newIndex, int& newKey);
};

// B 树类
class BTree {
public:
    Node* root;
    int t;

    BTree(int _t) : t(_t), root(nullptr) {}

    void insert(int k);
    void search(int k);
    void traverse(Node* node);
};

// 分裂子节点
void Node::splitChild(int i, Node* y) {
    Node* z = new Node(y->t, y->isLeaf);
    z->keys.resize(t - 1);
    z->children.resize(t);

    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    if (!y->isLeaf) {
        for (int j = 0; j < t; j++)
            z->children[j] = y->children[j + t];
    }

    y->keys.resize(t - 1);
    if (!y->isLeaf)
        y->children.resize(t);

    for (int j = children.size() - 1; j >= i + 1; j--)
        children[j + 1] = children[j];

    children[i + 1] = z;

    for (int j = keys.size() - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[t - 1];

    y->keys.resize(t - 1);
    y->children.resize(t);
}

// 插入非满节点
void Node::insertNonFull(int k) {
    int i = keys.size() - 1;

    if (isLeaf) {
        keys.push_back(-1); // 临时占位
        while (i >= 0 && k < keys[i]) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;
    } else {
        while (i >= 0 && k < keys[i]) {
            i--;
        }
        i++;
        if (children[i]->keys.size() == 2 * t - 1) {
            splitChild(i, children[i]);
            if (k > keys[i])
                i++;
        }
        children[i]->insertNonFull(k);
    }
}

// 插入非满节点，带索引
void Node::insertNonFull(int k, int index) {
    int i = keys.size() - 1;

    if (isLeaf) {
        keys.insert(keys.begin() + index, k);
    } else {
        while (i >= index && k < keys[i]) {
            i--;
        }
        i++;
        if (children[i]->keys.size() == 2 * t - 1) {
            splitChild(i, children[i]);
            if (k > keys[i])
                i++;
        }
        children[i]->insertNonFull(k, index);
    }
}

// 插入非满节点，带索引和新索引
void Node::insertNonFull(int k, int index, int& newIndex) {
    int i = keys.size() - 1;

    if (isLeaf) {
        keys.insert(keys.begin() + index, k);
        newIndex = index;
    } else {
        while (i >= index && k < keys[i]) {
            i--;
        }
        i++;
        if (children[i]->keys.size() == 2 * t - 1) {
            splitChild(i, children[i]);
            if (k > keys[i])
                i++;
        }
        children[i]->insertNonFull(k, index, newIndex);
    }
}

// 插入非满节点，带索引、新索引和新键值
void Node::insertNonFull(int k, int index, int& newIndex, int& newKey) {
    int i = keys.size() - 1;

    if (isLeaf) {
        keys.insert(keys.begin() + index, k);
        newIndex = index;
    } else {
        while (i >= index && k < keys[i]) {
            i--;
        }
        i++;
        if (children[i]->keys.size() == 2 * t - 1) {
            splitChild(i, children[i]);
            if (k > keys[i])
                i++;
        }
        children[i]->insertNonFull(k, index, newIndex, newKey);
    }
}

// 插入操作
void BTree::insert(int k) {
    if (root == nullptr) {
        root = new Node(t, true);
        root->keys.push_back(k);
    } else {
        if (root->keys.size() == 2 * t - 1) {
            Node* s = new Node(t, false);
            s->children.push_back(root);
            s->splitChild(0, root);
            int i = 0;
            if (k > s->keys[0])
                i++;
            s->children[i]->insertNonFull(k);
            root = s;
        } else {
            root->insertNonFull(k);
        }
    }
}

// 查找操作
void BTree::search(int k) {
    Node* current = root;
    while (!current->isLeaf) {
        int i = 0;
        while (i < current->keys.size() && k > current->keys[i])
            i++;
        if (i < current->keys.size() && k == current->keys[i]) {
            cout << "找到键值 " << k << endl;
            return;
        }
        current = current->children[i];
    }
    int i = 0;
    while (i < current->keys.size() && k > current->keys[i])
        i++;
    if (i < current->keys.size() && k == current->keys[i]) {
        cout << "找到键值 " << k << endl;
    } else {
        cout << "未找到键值 " << k << endl;
    }
}

// 遍历操作
void BTree::traverse(Node* node) {
    for (int i = 0; i < node->keys.size(); i++) {
        if (!node->isLeaf)
            traverse(node->children[i]);
        cout << node->keys[i] << " ";
    }
    if (!node->isLeaf)
        traverse(node->children[node->keys.size()]);
}