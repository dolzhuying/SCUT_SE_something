#include<bits/stdc++.h>

//降序
void bubble_sort(std::vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>i;j++){
            if(arr[j]>arr[j-1]){
               std::swap(arr[j],arr[j-1]);
            }
        }
    }
}