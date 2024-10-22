#include<bits/stdc++.h>
bool cmp(const std::vector<int>&a,std::vector<int>&b){//默认edge由 u，v和value组成
    return a[2]<b[2];
}

//并查集
int find(std::vector<int>&par,int i){
    if(i==par[i])return i;
    else return par[i]=find(par,par[i]);
}

void unionset(std::vector<int>&par,std::vector<int>&rank,int i,int j){
    int x=find(par,i),y=find(par,j);
    if(x!=y){
        if(rank[x]<rank[y]){
            par[x]=y;
        }
        else if(rank[x]>rank[y]){
            par[y]=x;
        }
        else {
            par[y]=x;
            rank[x]++;
        }
    }
}

std::vector<std::vector<int>> krustra(const std::vector<std::vector<int>>&edges,int N){
    std::sort(edges.begin(),edges.end(),cmp);//按边权从小到大，依次取出直到生成mst
    std::vector<std::vector<int>>mst;
    std::vector<int>par(N),rank(N);//祖宗节点和树的秩

    for(int i=0;i<N;i++){
        par[i]=i;
        rank[i]=0;
    }
    for(auto& e:edges){
        int x=find(par,e[0]),y=find(par,e[1]);
        if(x!=y){//非同一连通分量则合并并加入mst
            mst.push_back(e);
            unionset(par,rank,x,y);
        }
    }
    return mst;
}