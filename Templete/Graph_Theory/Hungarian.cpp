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
