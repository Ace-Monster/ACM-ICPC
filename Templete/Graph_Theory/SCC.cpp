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
