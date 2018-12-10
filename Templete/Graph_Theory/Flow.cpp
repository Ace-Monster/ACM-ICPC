const int maxn = 10005;
const int maxm = 100005;
const int inf = 0x3f3f3f3f;
struct Star{
	int to, w, next, rev;
}edge[maxm<<1];
int head[maxn], cnt;
void add_edge(int x, int y, int w, int rev){
	edge[cnt].to = y;
	edge[cnt].w = w;
	edge[cnt].next = head[x];
	edge[cnt].rev = rev;
	head[x] = cnt++;
}
void add(int x, int y, int w){
	add_edge(x, y, w, cnt+1);
	add_edge(y, x, 0, cnt-1);
}
bool flag[maxn];
int dfs(int v, int t, int f){
	if(v == t) return f;
	flag[v] = 1;
	for(int i = head[v];i != -1;i = edge[i].next){
		int& u = edge[i].to;
		int& w = edge[i].w;
		int rev = edge[i].rev;
		if(flag[u] || w <= 0) continue;
		int d = dfs(u, t, min(f, w));
		if(d > 0){
			w -= d;
			edge[rev].w += d;
			return d;
		}
	}
	return 0;
}
int max_flow(int s, int t){
	int ans = 0;
	while(true){
		memset(flag, 0, sizeof flag);
		int f = dfs(s, t, inf);
		if(!f) return ans;
		ans += f;
	}
}
