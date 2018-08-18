//LCA
//Tarjan_LCA
struct Task{
    int b,e,id;
    Task(int a,int be,int c):b(a),e(be),id(c) { }
};
bool flag[maxn];
int ans[i];//第i个任务的答案
int find(int x){//递归回溯并更新4个数组（类似并查集的路径压缩过程）
    if(f[x] == x) return x;
    int y = f[x];
    f[x] = find(y);
    return f[x];
}
void lca_tarjan(int u){
    flag[u] = true;
    vector<pair<int,int> >::iterator it = v[u].be();
    for(;it != v[u].en();it++){
        if(flag[(*it).fi]){//目标节点已被访问，由于存在后继节点，先挂载任务
            int t = find((*it).fi);
            if((*it).se > 0)//方向
                task[t].pb(Task((*it).fi, u, (*it).se));
            else{
                task[t].pb(Task(u, (*it).fi, -(*it).se));
            }
        }
    }
    for(int i = head[u];i != -1;i = edge[i].next){//先访问后继节点，保证树形结构
        if(!flag[edge[i].to]){
            lca_tarjan(edge[i].to);
            f[edge[i].to] = u;//由于可能存在当前节点u为子节点LCA的情况，在子节点没有搜索完成前不能指向父亲，否则路径压缩会造成树形结构破坏以及寻找LCA失败
        }
    }
    vector<Task>::iterator at = task[u].be();
    for(;at != task[u].en();at++){//回溯后处理任务
        int x = at->b,y = at->e,id = at->id;
       	ans[id] = find(x);//寻找LCA
    }
}

//ST_LCA
int d[maxn<<2][64],limit[maxn+5],number[maxn+5];
//d是ST表，limit是每个节点在欧拉序中第一次出现的下标，number记录的是重新编号对应的节点
int cnt = 0,num = 0;
void dfs(int u){//构造欧拉序
    d[++cnt][0] = ++num;
    int tnum = num;
    limit[u] = cnt;
    number[num] = u;
    for(int i = head[u];i != -1;i = edge[i].next){
        dfs(edge[i].to);
        d[++cnt][0] = tnum;
    }
    return;
}
void makst(int u){//建立ST表
	dfs(u);
    for(int j = 1;(1<<j) <= cnt;j++)
        for(int i = 1;(i + (j << 1) - 1) <= cnt;i++)
            d[i][j] = min(d[i][j-1], d[i + (1<<(j-1))][j-1]);
}
int query(int l,int r){//询问LCA
    int k = log2(r-l+1)+eps;
    return min(d[l][k], d[r-(1<<k)+1][k]);
}
