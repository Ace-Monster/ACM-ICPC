typedef vector<int> vi;
const int maxn = 100005;
vi edge[maxn];
int f[maxn],d[maxn];//父亲编号,深度 
int size[maxn], son[maxn], rk[maxn], top[maxn], id[maxn];
//size[u]:u为根的子节点个数
//son[u]:u的重儿子
//rk[u]:编号u(dfs序)在原图中的编号
//top[u]:u节点所在链的最顶端
//id[u]:u节点在dfs序中的编号

void dfs1(int u, int fa, int dep){//第一遍dfs
	f[u] = fa;
	d[u] = dep++;
	size[u] = 1;
	for(auto i : edge[u]){
		if(i == fa) continue;
		dfs1(i,u,dep);
		size[u] += size[i];
		if(size[i] > size[son[u]])
			son[u] = i;
	}
}

int cnt;//第二边dfs 
void dfs2(int u, int t){
	top[u] = t;
	id[u] = ++cnt;
	rk[cnt] = u;
	//sum[cnt] = sum[cnt-1]+a[u]-a[f[u]]; //差分树
	if(!son[u]) return;
	dfs2(son[u], t);
	for(auto i:edge[u]){
		if(i != son[u] && i != f[u])
			dfs2(i, i);
	}
} 

//线段树维护树链 
void UPD(int x, int y){
	while(top[x] != top[y]){
		if(d[top[x]] < d[top[y]]) swap(x, y);
		update(id[top[x]], id[x], 1, n, 1);//线段树更新 
		x = f[top[x]];
	}
	if(d[x] < d[y]) swap(x, y);
	update(id[y], id[x], 1, n, 1);//线段树更新 
}

//线段树查询树链（查询某条链的和） 
ll QUE(int x, int y){
	ll res = 0;
	while(top[x] != top[y]){
		if(d[top[x]] < d[top[y]]) swap(x, y);
		res += query(id[top[x]], id[x], 1, n, 1);//线段树查询 
		x = f[top[x]];
	}
	if(d[x] < d[y]) swap(x, y);
	res += query(id[y], id[x], 1, n, 1);//线段树查询 
	return res;
}


