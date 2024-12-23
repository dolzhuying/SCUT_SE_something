#include<bits/stdc++.h>
//升序(2-way)
void quick_sort(std::vector<int>&arr,int l,int r){
    int n=arr.size();
    int i=l,j=r,flag=arr[(i+j)>>1];
    do{
        while(arr[i]<flag)i++;
        while(arr[j]>flag)j--;
        if(i<=j){
            std::swap(arr[i],arr[j]);
            i++;j--;
        }
    }while(i<=j);
    if(i<r)quick_sort(arr,i,r);
    if(l<j)quick_sort(arr,l,j);
}


//median-of=three
int medianOfThree(int arr[], int left, int right) {
    int center = (left + right) / 2;

    // 将左、中、右三个元素按顺序排列
    if (arr[left] > arr[center]) std::swap(arr[left], arr[center]);
    if (arr[left] > arr[right]) std::swap(arr[left], arr[right]);
    if (arr[center] > arr[right]) std::swap(arr[center], arr[right]);

    // 将中位数移到右端 -1 的位置
    std::swap(arr[center], arr[right - 1]);
    return arr[right - 1];
}

//快速排序的分区函数
int partition(int arr[], int left, int right) {
    int pivot = medianOfThree(arr, left, right);
    int i = left, j = right - 1;

    while (true) {
        while (arr[++i] < pivot) {}
        while (arr[--j] > pivot) {}

        if (i < j) {
            std::swap(arr[i], arr[j]);
        } else {
            break;
        }
    }

    std::swap(arr[i], arr[right - 1]);
    return i;
}

// 快速排序函数
void quickSort(int arr[], int left, int right) {
    if (left >= right) return;

    int pivotIndex = partition(arr, left, right);
    quickSort(arr, left, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, right);
}

/*
template <typename E, typename Comp>
void quickSort(E A[], int i, int j) {
    if (j <= i) return; 
 
    int pivotindex = findpivot(A, i, j); 
    swap(A, pivotindex, j);  

    int k = partition<E,Comp>(A, i, j-1, A[j]);
    swap(A, k, j);   // Put pivot in place

    quickSort<E,Comp>(A, i, k-1); 
    quickSort<E,Comp>(A, k+1, j);
}
template <typename E, typename Comp>
int partition(E A[], int l, int r, E& pivot) {
  do {
     while (Comp::prior(A[++l], pivot));
     while ((l<r) && Comp::prior(A[--r],pivot));
    
     swap(A, l, r); 
  } while (l < r); 
  swap(A, l, r);   [最后一次交换是多余的]
  return l; 
}

*/