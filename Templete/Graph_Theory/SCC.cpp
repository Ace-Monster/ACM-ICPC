//Tarjan强连通分量
stack<int> q;//栈
int gra[maxn+5];//上色
int dfn[maxn+5],low[maxn+5];//判断
int n;//点
int ind = 0,scc = 0;//ind->计数器,scc->强连通块数量
bool flag[maxn+5];//标记
void tarjan(const int u){
	dfn[u] = low[u] = ++ind;
	q.push(u);
	flag[u] = 1;
	for(auto i:edge[u]){
		int to = i;
		if(flag[to] == 0){
			tarjan(to);
			low[u] = min(low[u],low[to]);
		}
		else if(gra[to] == 0)//判断是否还在栈内
			low[u] = min(low[u],dfn[to]);
	}
	if(dfn[u] == low[u]){
		size[++scc] = 1;//scc:缩点图点数量 
		while(q.top() != u) {
			gra[q.top()] = low[u];//染色 
			size[scc]++;//强连通大小 
			q.pop();
		}
		gra[u] = low[u];
		q.pop();
	}
}

//2-sat
//每种情况有两个状态 0-1
//i0与j0互斥 => 连接i0->j1, j0->i1
//若存在一种情况其两个状态强连通，则矛盾 
bool solve(){
	for(int i = 1;i <= m;i++){
		cin >> a >> b;
		int ta = (a <= n) ? a+n : a-n;
		int tb = (b <= n) ? b+n : b-n; 
		add(a, tb);
		add(b, ta);
	}
	
	for(int i = 1;i <= n;i++)
		if(!flag[i]) tarjan(i);
		
	for(int i = 1;i <= n;i++)
		if(gra[i] == gra[i+1]) return false;
	return true;
}

//初始化
void init(int n){
	memset(flag, 0, sizeof flag);
	memset(gra, 0, sizeof gra);
	ind = scc = 0;
	for(int i = 1;i <= n;i++) edge[i].clear();
}