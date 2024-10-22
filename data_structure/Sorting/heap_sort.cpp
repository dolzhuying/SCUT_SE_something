#include<bits/stdc++.h>

//小根堆
void adjustdown(std::vector<int>&arr,int n,int root){
    int parent=root;
    int child=parent*2+1;
    while(child<n){
        if(child+1<n&&arr[child+1]>arr[child]){
            child++;
        }
        if(arr[parent]<arr[child])break;
        std::swap(arr[parent],arr[child]);
        parent=child;
        child=child*2+1;
    }
}

void heap_sort(std::vector<int>&arr){
    int n=arr.size();
    int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--){
		adjustdown(arr, n, i);
	}
    int end=n-1;
    while(end>0){
        std::swap(arr[0],arr[end]);
        adjustdown(arr,end,0);
        end--;
    }
}