#include<bits/stdc++.h>

//小根堆，降序
void adjustdown(std::vector<int>&arr,int n,int root){
    int parent=root;
    int tmp=arr[parent];
    int child=parent*2+1;
    for(;parent*2+1<n;parent=child){
        child=parent*2+1;
        if(child+1<n&&arr[child]>arr[child+1]){
            ++child;
        }
        if(arr[child]<tmp){
            arr[parent]=arr[child];
        }
        else break;
    }
    arr[parent]=tmp;
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

