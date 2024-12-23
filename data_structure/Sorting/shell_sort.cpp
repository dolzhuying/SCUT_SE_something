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
            for(;j>=0&&arr[j]>tmp;j-=gap){
                arr[j+gap]=arr[j];
            }
            arr[j+gap]=tmp;
        }
    }
}

//ppt升序
template <typename Comparable>
void shellsort( vector<Comparable> & a ) {
    for( int gap = a.size( ) / 2; gap > 0; gap /= 2 ){
         for( int i = gap; i < a.size( ); ++i ) {
            Comparable tmp = std::move( a[ i ] );
            int j=i;
            for(; j >= gap && tmp < a[ j - gap ]; j -= gap )
                 a[ j ] = std::move( a[ j - gap ] );
            a[ j ] = std::move( tmp );
        }
    }
};
