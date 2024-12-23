#include<bits/stdc++.h>
//升序
void insertion_Sort(std::vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        int end=i;
        int tmp=arr[end+1];
        while(end>=0){
            if(tmp<arr[end]){
                arr[end+1]=arr[end];
                end--;
            }
            else break;
        }
        arr[end+1]=tmp;
    }
}

//降序
void insertion_sort(std::vector<int>&arr){
    int n=arr.size();
    if(n<=1)return;
    for(int i=1;i<n;i++){
        for(int j=i;j>0&&arr[j]>arr[j-1];j--){
            std::swap(arr[j],arr[j-1]);
        }
    }
}

