#include<bits/stdc++.h>

template <typename Comparable>
class BinaryHeap {//小根堆
public:
    // 构造函数，初始化一个空堆，默认容量为100
    explicit BinaryHeap(int capacity = 100) : currentSize(0), array(capacity + 1) {}

    // 构造函数，使用给定的向量初始化堆，并调用 buildHeap 方法构建堆
    explicit BinaryHeap(const std::vector<Comparable> & items) : currentSize(items.size()), array(items.size() + 1) {
        for (size_t i = 0; i < items.size(); ++i) {
            array[i + 1] = items[i];
        }
        buildHeap();
    }

    // 查找并返回堆顶元素
    const Comparable & findMin() const {
        if (isEmpty()) {
            throw std::underflow_error("Heap is empty");
        }
        return array[1];
    }

    // 插入常量引用类型的元素
    void insert(const Comparable & x) {
        if (currentSize == array.size() - 1) {
            array.resize(array.size() * 2);
        }
        int hole = ++currentSize;
        array[0] = x;

        for (; x < array[hole / 2]; hole /= 2) {
            array[hole] = array[hole / 2];
        }
        array[hole] = x;
    }

    // 插入右值引用类型的元素
    void insert(Comparable && x) {
        if (currentSize == array.size() - 1) {
            array.resize(array.size() * 2);
        }
        int hole = ++currentSize;
        array[0] = std::move(x);//暂存在array[0]，不是堆顶元素

        for (; array[0] < array[hole / 2]; hole /= 2) {
            array[hole] = array[hole / 2];
        }
        array[hole] = std::move(array[0]);
    }

    // 删除堆顶元素，即最小值
    void deleteMin() {
        if (isEmpty()) {
            throw std::underflow_error("Heap is empty");
        }
        array[1] = std::move(array[currentSize--]);
        percolateDown(1);
    }

    // 删除堆顶元素，并将最小值赋值给传入的引用参数
    void deleteMin(Comparable & minItem) {
        if (isEmpty()) {
            throw std::underflow_error("Heap is empty");
        }
        minItem = std::move(array[1]);
        array[1] = std::move(array[currentSize--]);
        percolateDown(1);
    }

private:
    int currentSize; // 堆中当前元素的数量
    std::vector<Comparable> array; // 存储堆元素的数组

    // 从给定的数组构建堆
    void buildHeap() {
        for (int i = currentSize / 2; i > 0; --i) {
            percolateDown(i);
        }
    }

    // 从指定位置向下调整堆结构以保持堆性质
    void percolateDown(int hole) {
        int child;
        Comparable tmp = std::move(array[hole]);

        for (; hole * 2 <= currentSize; hole = child) {
            child = hole * 2;
            if (child != currentSize && array[child + 1] < array[child]) {
                ++child;
            }
            if (array[child] < tmp) {
                array[hole] = std::move(array[child]);
            } else {
                break;
            }
        }
        array[hole] = std::move(tmp);
    }

    // 检查堆是否为空
    bool isEmpty() const {
        return currentSize == 0;
    }
};