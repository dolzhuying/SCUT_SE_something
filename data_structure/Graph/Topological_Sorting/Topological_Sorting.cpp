#include<bits/stdc++.h>

//邻接表存图,保证图联通且为dag
void topsorting(std::vector<std::vector<int>>&graph , int n){
    std::vector<int>res;//存储拓扑序列
    std::vector<int>in(n,0);
    for(int i=0;i<n;i++){
        for(auto&j:graph[i]){
            in[j]++;
        }
    }
    std::queue<int>q;
    for(int i=0;i<n;i++){
        if(!in[i])q.push(i);
    }
    
    while(!q.empty()){
        int u=q.front();
        q.pop();
        res.push_back(u);
        for(auto&v:graph[u]){
            in[v]--;
            if(!in[v])q.push(v);
        }
    }

}

