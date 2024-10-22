#include<bits/stdc++.h>

//升序
void selection_sort(std::vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        int min_id=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_id]){
                min_id=j;
            }
        }
        std::swap(arr[i],arr[min_id]);
    }
}