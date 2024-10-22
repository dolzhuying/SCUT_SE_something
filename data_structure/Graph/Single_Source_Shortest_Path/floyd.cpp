#include<bits/stdc++.h>
using i64=long long;


void floyd(i64 n,i64 m){
    i64 u,v,value;
    std::vector<std::vector<i64>>adj(n,std::vector<i64>(n,INT_MAX));
    for(int i=0;i<n;i++){
        adj[i][i]=0;//自己到自己最短路为0
    }
    for(int i=0;i<m;i++){
        std::cin>>u>>v>>value;
        adj[u][v]=std::min(adj[u][v],value);
    }
    //floyd 更新两点间最短路，k为中间节点
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[i][j]>adj[i][k]+adj[k][j]){
                    adj[i][j]=adj[i][k]+adj[k][j];
                }
            }
        }
    }

    //查询两点间最短路
    auto query=[&](int a,int b){
       return adj[a][b]==INT_MAX?-1:adj[a][b];//-1表示无最短路
    };
    
}