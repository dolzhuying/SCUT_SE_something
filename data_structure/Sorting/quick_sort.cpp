#include<bits/stdc++.h>
//升序
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