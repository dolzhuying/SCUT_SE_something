#include <iostream>

struct Stack {
    int *arr; 
    int capacity;  
    int top;  

    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    bool push(int value) {
        if (top >= capacity - 1) {
            return false;  // 栈满
        }
        arr[++top] = value;
        return true;
    }

    int pop() {
        if (top < 0) {
            return -1;  // 栈空
        }
        return arr[top--];
    }

    int topElement() const {
        if (top < 0) {
            return -1;  // 栈空
        }
        return arr[top];
    }

    bool isEmpty() const {
        return top == -1;
    }
};