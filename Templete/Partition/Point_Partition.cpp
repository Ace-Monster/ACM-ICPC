const int maxn = 10005;
const int INF = 0x3f3f3f3f;
struct Star {
	int next, to, l;
	void insert(int a, int b, int c) {
		to = a, l = b, next = c;
	}
}edge[maxn];
int head[maxn], cnt = 0;
int rt = 0, N;
int siz[maxn], dp[maxn], flag[maxn], deep[maxn], d[maxn];
int getroot(int x, int fa) {//获取重心,返回值为副产物子节点的数量
	siz[x] = 0, dp[x] = 1;//dp存储以这个节点为父亲的子树节点数量
	for (int i = head[x];i != -1;i = edge[i].next) {
		int to = edge[i].to;
		if (to != fa && !flag[to]) {
			dp[x] += getroot(to, x);
			siz[x] = max(siz[x], dp[to]);//记录子树节点最大值
		}
	}
	siz[x] = max(siz[x], N - dp[x]);
	if (siz[rt] > siz[x])//根据重心的定义，子树节点最大值最小的节点为重心
		rt = x;
	return dp[x];
}
void getdeep(int x, int fa) {//递归获取从重心到达各个点的距离
	d[++cnt] = deep[x];//距离记录到deep[]数组内,d[]数组方便排序和滑窗
	for (int i = head[x];i != -1;i = edge[i].next) {
		int to = edge[i].to;
		if (to != fa && !flag[to]) {
			deep[to] = deep[x] + edge[i].l;
			getdeep(to, x);
		}
	}
}
int calc(int x, int k) {//获取当前子树中满足条件的节点对个数
	cnt = 0;
	getdeep(x, 0);
	sort(d + 1, d + cnt + 1);
	int sum = 0;
	for (int i = 1, j = cnt;i < j;) {//滑窗
		if (d[j] + d[i] <= k)
			sum += (j - i), i++;
		else
			j--;
	}
	return sum;
}
int dfs(int x, int n, int k) {//dfs求解答案
	deep[x] = 0;
	flag[x] = true;//表示重心已被摘除
	int ans = calc(x, k);//计算符合条件的节点对数量
	for (int i = head[x];i != -1;i = edge[i].next) {
		int to = edge[i].to;
		if (!flag[to]) {
			deep[to] = edge[i].l;
			ans -= calc(to, k);//删除没有经过重心的节点对数量，避免重复计算
			N = dp[to];//利用之前getroot计算得到的子树节点数量
			rt = 0;
			getroot(to, 0);//获得子树的重心
			ans += dfs(rt, n, k);//进入to节点所在子树的重心
		}
	}
	return ans;
}
int solve(int n, int k) {
	memset(flag, 0, sizeof flag);
	rt = 0, N = n, siz[0] = INF;
	getroot(1, 0);
	return dfs(rt, n, k);
}
