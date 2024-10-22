#include <iostream>

class CircularQueue {
private:
    int *arr;  // 动态数组
    int front;  // 队首索引
    int rear;  // 队尾索引
    int capacity;  // 队列容量

public:
    CircularQueue(int size) : capacity(size+1), front(0), rear(-1) {//capacity预留多1个位置作为判断队满的标志位
        arr = new int[capacity];
    }

    ~CircularQueue() {
        delete[] arr;
    }

    // 入队操作
    void enqueue(int value) {
        if (isFull()) {
            return ;  // 队列已满
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
    }

    // 出队操作
    void dequeue() {
        if (isEmpty()) {
            return ;  // 队列为空
        }
        int value = arr[front];
        front = (front + 1) % capacity;
    }

    // 获取队首元素
    int frontElement() const {
        if (isEmpty()) {
            return -1;  // 队列为空
        }
        return arr[front];
    }

    // 获取队尾元素
    int rearElement() const {
        if (isEmpty()) {
            return -1;  // 队列为空
        }
        return arr[rear];
    }

    // 判断队列是否为空
    bool isEmpty() const {
        return front == (rear + 1) % capacity;
    }

    // 判断队列是否已满
    bool isFull() const {
        return front == (rear + 2) % capacity;
    }
};