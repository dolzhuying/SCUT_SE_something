#include<bits/stdc++.h>
const int N=1e5+10;
std::vector<int>pre(N),rank(N);
void init(int n){
    for(int i=0;i<n;i++){
        pre[i]=i;
        rank[i]=1;
    }
}

int find(int x){
    if(pre[x]==x)return x;
    return pre[x]=find(pre[x]);
}

void join(int x,int y){
    int rootx=find(x);
    int rooty=find(y);
    if(rootx==rooty)return;
    if(rank[rootx]>rank[rooty]){
        pre[rooty]=rootx;
    }
    else if(rank[rootx]<rank[rooty]){
        pre[rootx]=rooty;
    }
    else{
        pre[rooty]=rootx;
        rank[rootx]++;
    }
}