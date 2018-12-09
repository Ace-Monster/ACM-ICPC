//前向星
struct Star{
	int to,next;
}edge[maxv];
int head[maxn+5];
void add_edge(int x,int y){//x->y
	edge[++cnt].to = y;
	edge[cnt].next = head[x];
	head[x] = cnt;
}


//并查集
int f[maxn];
void init(int n){
	for(int i = 1;i <= n;i++)
		f[i] = i;
}
int find(int x){
	if(f[x] == x)
		return x;
	f[x] = find(f[x]);
	return f[x];
}
void unite(int x,int y){
	x = find(x);
	y = find(y);
	if(y == x) return;
	f[x] = y;
	return;
}


//Tarjan强连通分量
stack<int> q;//栈
int gra[maxn+5];//上色
int dfn[maxn+5],low[maxn+5];//判断
int n;//点
int ind = 0,gcc = 0;//ind->计数器,gcc->强连通块数量
bool flag[maxn+5];//标记
void tarjan(const int u){
	dfn[u] = low[u] = ++ind;
	q.push(u);
	flag[u] = 1;
	for(int i = head[u];i != -1;i = edge[i].next){
		int to = edge[i].to;
		if(flag[to] == 0){
			tarjan(to);
			low[u] = min(low[u],low[to]);
		}
		else if(gra[to] == 0)//判断是否还在栈内
			low[u] = min(low[u],dfn[to]);
	}
	if(dfn[u] == low[u]){
		scc++;
		while(q.top() != u) {
			gra[q.top()] = low[u];
			q.pop();
		}
		gra[u] = low[u];
		q.pop();
	}
}


//Dijkstra
int s[maxn];
void Dij(int u){
	memset(s, inf, sizeof s);
	s[u] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;//注意> >空格
	q.push(make_pair(0, u));
	while(q.size()){
		pair<int, int> p = q.top();
		q.pop();
		if(p.fi > s[p.se]) continue;
		for(int i = head[p.se];i != -1;i = edge[i].next){
			if(s[edge[i].to] > p.fi + edge[i].w){
				s[edge[i].to] = p.fi + edge[i].w;
				q.push(mp(s[edge[i].to], edge[i].to));
			}
		}
	}
}


//SPFA
int d[maxn];
bool flag[maxn];
void spfa(int u) {
	memset(d, 0, sizeof d);
	memset(flag, 0, sizeof flag);
	queue<int> p;
	p.push(u);
	while (p.size()) {
		int t = p.front();
		p.pop();
		for (int i = head[t];i != -1;i = edge[i].next)
			int to = edge[i].to;
			if (d[to] < d[t] + edge[i].w) {
				d[to] = d[t] + edge[i].w;
				p.push(to);
			}
	}
}


//Floyd-Warshall
for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(d[i][j] > d[i][k]+d[k][j]) 
                d[i][j] = d[i][k]+d[k][j];


//匈牙利
bool flag[maxn];
int match[maxn];
bool find(int u) {
	for (int i = head[u];i != -1;i = edge[i].next) {
		int to = edge[i].to;
		if (!flag[to]) {
			flag[to] = true;
			if (match[to] == 0 || find(match[to])) {
				match[to] = u;
				return true;
			}
		}
	}
	return false;
}
int hungarian(int n, int m) {
	int sum = 0;
	for (int i = 1;i <= n;i++) {
		if (find(i))
			sum++;
		memset(flag, 0, sizeof flag);
	}
	return sum;
}
int Minimum_point_coverage(int n){//最小点覆盖
	return hungarian(n);
}
int Minimum_edge_coverage(int n){//最小边覆盖
	return n - hungarian(n);
}
int Minimum_path_coverage(int n){//DAG最小路径覆盖(不可相交)
	//对原图建立2n顶点二分图，方向由X集合指向Y集合
	//可相交做法:转换为不可相交二分图
	//n为二分图顶点数 = 原图顶点数×2
	return n/2 - hungarian(n);
}
int Independent_point_set(int n){//最大独立集
	return n - hungarian(n);
}


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
