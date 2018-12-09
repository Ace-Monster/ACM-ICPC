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
