#include<bits/stdc++.h>
//升序
void shell_sort(std::vector<int>&arr){
    int n=arr.size();
    int gap=n;
    while(gap>1){
        gap/=2;
        for(int i=gap;i<n;i++){
            int tmp=arr[i];
            int j=i-gap;
            for(int j=i-gap;j>=0&&arr[j]>tmp;j-=gap){
                arr[j+gap]=arr[j];
            }
            arr[j+gap]=tmp;
        }
    }
}