## 并查集

并查集是一种树型的数据结构，用于处理一些不相交集合的合并及查询问题（即所谓的并、查）。比如说，我们可以用并查集来判断一个森林中有几棵树、某个节点是否属于某棵树等。

主要构成：
并查集主要由一个整型数组pre[ ]和两个函数find( )、join( )构成。
数组 `pre[ ]` 记录了每个点的前驱节点是谁，函数 `find(x)` 用于查找指定节点 x 属于哪个集合，函数` join(x,y)` 用于合并两个节点 x 和 y 。

作用：
并查集的主要作用是求连通分量数量
