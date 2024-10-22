#include<bits/stdc++.h>

//升序
void bubble_sort(std::vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
               std::swap(arr[j],arr[j+1]);
            }
        }
    }
}