//Kruskal
struct Edge{
	int from, to, val;
	bool operator<(const Edge &x) const{
		return val < x.val;
	}
}edge[maxe];
Union-Find_set F;
int Kruskal(int n){//返回最小生成树的边权和
	F.init(n);
	sort(edge, edge + n);
	int ans = 0, cnt = 0, i = 0;//保证图联通的情况下不用判断i的大小
	while(cnt < n - 1){
		int from = edge[i].from, to = edge[i].to;
		if(F.find(from) != F.find(to)){
			F.unite(from, to);
			cnt++;
			ans += edge[i].val;
		}
		i++;
	}
	return ans;
}