#include<bits/stdc++.h>
//邻接矩阵存图
void prim(std::vector<std::vector<int>>&graph){
    int n=graph.size(),m=graph[0].size();
    int v_num=std::max(n,m);//顶点数

    std::vector<int>par(v_num,-1);//存储结果MST
    std::vector<int>dis(v_num,INT_MAX);//最小权重
    std::vector<bool>mstset(v_num,false);//节点i是否已进入mst

    dis[0]=0;
    
    for(int now=0;now<v_num;now++){
        int min_dis=INT_MAX,min_id=-1;
        for(int v=0;v<v_num;v++){//寻找当前未访问的最小权重的点
            if(!mstset[v]&&dis[v]<min_dis){
                min_dis=dis[v];
                min_id=v;
            }
        }
        if(min_id==-1)break;//找不到最小权重点，说明图不连通

        mstset[min_id]=1;//进入mst
        for(int v=0;v<v_num;v++){//遍历与当前最小节点邻接的点，并更新节点对应最小权值和存储mst
            if(!mstset[v]&&graph[min_id][v]!=INT_MAX&&graph[min_id][v]<dis[v]){//默认节点间无边用INTMAX表示
                par[v]=min_id;
                dis[v]=graph[min_id][v];
            }
        }

    }
    
}

struct cmp {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.first > b.first;
    }
};
//堆优化Prim，邻接矩阵存图
void prim_heap(std::vector<std::vector<int>>& graph) {
    int n = graph.size(), m = graph[0].size();
    int v_num = std::max(n, m); // 顶点数

    std::vector<int> par(v_num, -1); // 存储结果MST
    std::vector<int> dis(v_num, INT_MAX); // 最小权重
    std::vector<bool> mstset(v_num, false); // 节点i是否已进入mst

    // 使用优先队列（小根堆）
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, cmp> pq;

    dis[0] = 0;
    pq.push({0, 0}); // {距离, 节点}

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (mstset[u]) continue; // 已经加入MST，跳过

        mstset[u] = true;

        for (int v = 0; v < v_num; ++v) {
            if (!mstset[v] && graph[u][v] != INT_MAX && graph[u][v] < dis[v]) {
                par[v] = u;
                dis[v] = graph[u][v];
                pq.push({dis[v], v});
            }
        }
    }
}