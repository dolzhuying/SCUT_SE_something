#include<bits/stdc++.h>
//堆优化dijkstra，使用小根堆，邻接表存图，O((n+m)log m)
struct edge{
    int to,val;
};
struct cmp{//堆优化比较器
    bool operator()(std::pair<int,int>&a,std::pair<int,int>&b){
        return a.second>b.second;
    }
};

void dijkstra_heap(const std::vector<std::vector<edge>>&graph,int start,std::vector<int>&dis){
    int n=graph.size();
    std::vector<bool>vis(n,false);//初始化为未访问
    dis.assign(n,INT_MAX);//所有点距离初始化为max
    dis[start]=0;
    
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,cmp>pq;//小根堆存储当前已知最短距离
    pq.push({start,0});
    while(!pq.empty()){
        int curnode=pq.top().first;
        int curdis=pq.top().second;
        pq.pop();

        vis[curnode]=1;//标记访问
        for(auto& e:graph[curnode]){
            int nextnode=e.to;
            int nextdis=e.val;

            if(!vis[nextnode]&&dis[nextnode]>curdis+nextdis){//未访问且满足更优路径，进队
                dis[nextnode]=curdis+nextdis;
                pq.push({nextnode,dis[nextnode]});

            }
        }
    }

}

//不使用堆优化，O(N^2)，邻接矩阵存图
void dijkstra(const std::vector<std::vector<int>>&graph,int start,std::vector<int>&dis){
    int n=graph.size();
    dis.assign(n,INT_MAX);
    std::vector<bool>vis(n,false);
    dis[start]=0;
    for(int i=0;i<n;i++){
        int curdis=INT_MAX,curid=-1;
        for(int j=0;j<n;j++){
            if(!vis[j]&&dis[j]<curdis){//等价于优先队列功能，找出当前最小距离的点
                curdis=dis[j];
                curid=j;
            }
        }
        if(curid==-1)break;//图可能不连通，退出
        vis[curid]=1;
        for(int k=0;k<n;k++){//从当前结点出发遍历所有直接相连的点
            if(!vis[k]&&graph[curid][k]!=INT_MAX&&dis[k]>dis[curid]+graph[curid][k]){
                dis[k]=dis[curid]+graph[curid][k];
            }
            else if(vis[k]&&dis[k]>dis[curid]+graph[curid][k]){
                dis[k]=dis[curid]+graph[curid][k];
            }
        }

    }
}


