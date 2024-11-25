#include<bits/stdc++.h>
#include<chrono>
#include<ctime>

// 升序排序

// 冒泡排序
// 原理：通过多次遍历数组，每次将相邻的两个元素进行比较，如果前一个元素大于后一个元素，则交换它们的位置。
// 这样每一轮遍历后，最大的元素会“冒泡”到数组的末尾。
void bubble_sort(std::vector<int>&arr){
    int n=arr.size();
    // 外层循环控制遍历次数，共 n-1 次
    for(int i=0;i<n-1;i++){
        // 内层循环进行相邻元素比较和交换，每次遍历后最后一个元素已经是最大值，所以范围逐渐缩小
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
               std::swap(arr[j],arr[j+1]);
            }
        }
    }
}

// 堆排序
// 原理：构建一个大根堆，然后将堆顶元素与最后一个元素交换，再重新调整堆，重复此过程直到所有元素有序。
void adjustdown(std::vector<int>&arr, int n, int root){
    int parent = root;
    int child = parent * 2 + 1;
    // 调整堆的过程，确保以 root 为根的子树满足大根堆的性质
    while(child < n){
        // 如果右孩子存在且大于左孩子，则选择右孩子
        if(child + 1 < n && arr[child + 1] > arr[child]){
            child++;
        }
        // 如果父节点大于等于孩子节点，说明已经满足大根堆的性质，退出循环
        if(arr[parent] >= arr[child]) break;
        // 否则交换父节点和孩子节点
        std::swap(arr[parent], arr[child]);
        // 更新父节点和孩子节点的索引
        parent = child;
        child = child * 2 + 1;
    }
}

void heap_sort(std::vector<int>&arr){
    int n = arr.size();
    // 构建初始大根堆，从最后一个非叶子节点开始向上调整
    for (int i = (n - 1 - 1) / 2; i >= 0; i--){
        adjustdown(arr, n, i);
    }
    int end = n - 1;
    // 交换堆顶元素和最后一个元素，然后重新调整堆
    while(end > 0){
        std::swap(arr[0], arr[end]);
        adjustdown(arr, end, 0);
        end--;
    }
}

// 插入排序
// 原理：将数组分为已排序部分和未排序部分，每次从未排序部分取出一个元素，插入到已排序部分的适当位置。
void insertion_sort(std::vector<int>&arr){
    int n = arr.size();
    // 遍历未排序部分
    for(int i = 0; i < n - 1; i++){
        int end = i;
        int tmp = arr[end + 1];
        // 在已排序部分找到合适的位置插入当前元素
        while(end >= 0){
            if(tmp < arr[end]){
                arr[end + 1] = arr[end];
                end--;
            } else {
                break;
            }
        }
        arr[end + 1] = tmp;
    }
}

// 快速排序
// 原理：选择一个基准元素，将数组分为两部分，左边部分小于基准，右边部分大于基准，递归地对这两部分进行排序。
void quick_sort(std::vector<int>&arr, int l, int r){
    int i = l, j = r;
    int flag = arr[(i + j) >> 1];
    // 分区过程
    do{
        while(arr[i] < flag) i++;
        while(arr[j] > flag) j--;
        if(i <= j){
            std::swap(arr[i], arr[j]);
            i++; j--;
        }
    } while(i <= j);
    // 递归排序左右两部分
    if(i < r) quick_sort(arr, i, r);
    if(l < j) quick_sort(arr, l, j);
}

// 选择排序
// 原理：每次从未排序部分选择最小的元素，放到已排序部分的末尾。
void selection_sort(std::vector<int>&arr){
    int n = arr.size();
    // 遍历未排序部分
    for(int i = 0; i < n - 1; i++){
        int min_id = i;
        // 找到未排序部分的最小元素
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min_id]){
                min_id = j;
            }
        }
        // 将最小元素放到已排序部分的末尾
        std::swap(arr[i], arr[min_id]);
    }
}

// 归并排序
// 原理：将数组分成两部分，分别排序，然后合并成一个有序数组。
void Merge(std::vector<int>& sourceArr, std::vector<int>& tempArr, int startIndex, int midIndex, int endIndex) {
    int i = startIndex, j = midIndex + 1, k = startIndex;
    // 合并两个有序子数组
    while (i != midIndex + 1 && j != endIndex + 1) {
        if (sourceArr[i] <= sourceArr[j])
            tempArr[k++] = sourceArr[i++];
        else
            tempArr[k++] = sourceArr[j++];
    }
    // 处理剩余部分
    while (i != midIndex + 1)
        tempArr[k++] = sourceArr[i++];
    while (j != endIndex + 1)
        tempArr[k++] = sourceArr[j++];
    // 将临时数组中的结果复制回原数组
    for (i = startIndex; i <= endIndex; i++)
        sourceArr[i] = tempArr[i];
}

void MergeSort(std::vector<int>& sourceArr, std::vector<int>& tempArr, int startIndex, int endIndex) {
    if (startIndex < endIndex) {
        int midIndex = startIndex + (endIndex - startIndex) / 2;
        // 递归排序左右两部分
        MergeSort(sourceArr, tempArr, startIndex, midIndex);
        MergeSort(sourceArr, tempArr, midIndex + 1, endIndex);
        // 合并两部分
        Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
    }
}

void MergeSort(std::vector<int>& arr) {
    if (arr.empty()) return;
    std::vector<int> tempArr(arr.size());
    MergeSort(arr, tempArr, 0, arr.size() - 1);
}

// 排序类型枚举
enum SortType { insertion, bubble, selection, heap, merge, quick };

// 统一调用排序函数，并记录时间
void solve(std::vector<int>&arr, SortType sort_type){
    std::map<SortType, std::string> sortTypeToString = {
        { insertion, "insertion" },
        { bubble, "bubble" },
        { selection, "selection" },
        { heap, "heap" },
        { merge, "merge" },
        { quick, "quick" }
    };
    
    // 记录排序前的时间
    auto before = std::chrono::high_resolution_clock::now();
    auto before_ = std::chrono::duration_cast<std::chrono::microseconds>(before.time_since_epoch()).count();
    // 根据排序类型调用相应的排序函数
    switch(sort_type){
        case insertion: insertion_sort(arr); break;
        case bubble: bubble_sort(arr); break;
        case selection: selection_sort(arr); break;
        case heap: heap_sort(arr); break;
        case merge: MergeSort(arr); break;
        case quick: quick_sort(arr, 0, arr.size() - 1); break;
    }
    // 记录排序后的时间
    auto after = std::chrono::high_resolution_clock::now();
    auto after_ = std::chrono::duration_cast<std::chrono::microseconds>(after.time_since_epoch()).count();
    // 输出排序时间和排序类型
    std::cout << sortTypeToString.at(sort_type) << "_sort :" << 1.0 * (after_ - before_) / 1000 << " ms \n";
}

int main(){
    std::fstream f;
    //打开数据文件
    f.open("sort10000.txt", std::ios::in);
    //f.open("sort1000.txt", std::ios::in);
    //f.open("sort100.txt", std::ios::in);
    
    std::string s;
    std::vector<int> arr;
    // 读取文件中的数据
    while(getline(f, s)){
        std::stringstream ss(s);
        int num;
        while(ss >> num){
            arr.push_back(num);
        }
    }
    f.close();
    std::cout << "size:" << arr.size() << '\n';

    // 对不同排序算法进行测试
    solve(arr, insertion);
    solve(arr, bubble);
    solve(arr, selection);
    solve(arr, heap);
    solve(arr, merge);
    solve(arr, quick);

    return 0;
   
    
}