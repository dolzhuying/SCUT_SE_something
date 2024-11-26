
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void pushFront(Node*& head) {
    int x; cin >> x;
    Node* newNode = new Node{ x, head, nullptr };
    if (head) {
        head->prev = newNode;
    }
    head = newNode;
}

void pushBack(Node*& head) {
    int x; cin >> x;
    Node* newNode = new Node{ x, nullptr, nullptr };
    if (!head) {
        head = newNode;
    } else {
        Node* p = head;
        while (p->next) {
            p = p->next;
        }
        p->next = newNode;
        newNode->prev = p;
    }
}

Node* findNode(Node* head, int x) {
    Node* p = head;
    while (p && p->data != x) {
        p = p->next;
    }
    return p;
}

void insertNodeBack(Node* head, int position, int value) {
    if (!head || position <= 0) return;
    Node* p = head;
    for (int i = 1; i < position && p; ++i) {
        p = p->next;
    }
    if (p) {
        Node* newNode = new Node{ value, p->next, p };
        if (p->next) {
            p->next->prev = newNode;
        }
        p->next = newNode;
    }
}

Node* findNodeByPosition(Node* head, int position) {
    if (!head || position <= 0) return nullptr;
    Node* p = head;
    for (int i = 1; i < position && p; ++i) {
        p = p->next;
    }
    return p;
}

void eraseNode(Node*& head, int position) {
    if (!head || position <= 0) return;
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        delete temp;
        return;
    }
    Node* p = head;
    for (int i = 1; i < position - 1 && p; ++i) {
        p = p->next;
    }
    if (p && p->next) {
        Node* temp = p->next;
        p->next = temp->next;
        if (temp->next) {
            temp->next->prev = p;
        }
        delete temp;
    }
}

void insertionSort(Node*& head) {
    if (!head || !head->next) return;
    Node* dummy = new Node{ 0, head, nullptr };
    Node* current = head;
    while (current) {
        Node* next = current->next;
        Node* prev = dummy;
        Node* pos = dummy->next;
        while (pos && current->data > pos->data) {
            prev = pos;
            pos = pos->next;
        }
        prev->next = current;
        current->next = pos;
        if (pos) {
            pos->prev = current;
        }
        current->prev = prev;
        current = next;
    }
    head = dummy->next;
    head->prev = nullptr;
    delete dummy;
}

void printList(Node* head) {
    Node* p = head;
    while (p) {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << '\n';
}

void clearList(Node*& head) {
    Node* p = head;
    while (p) {
        Node* temp = p;
        p = p->next;
        delete temp;
    }
    head = nullptr;
}

int main() {
    // Node* head = nullptr;
    // pushBack(head);
    // pushBack(head);
    // pushBack(head);
    // printList(head);
    // insertNodeBack(head, 2, 100);
    // printList(head);
    // eraseNode(head, 2);
    // printList(head);
    // insertionSort(head);
    // printList(head);
    // clearList(head);
    // return 0;
}
