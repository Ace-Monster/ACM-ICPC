//RMQ问题倍增算法
//st[i][j]表示从i开始，长度为(1<<j)的区间内的最大(小)值 
const int maxn = 100005;
const int logn = (log(maxn)/log(2))+1;
const ld eps = 1e-9;
int st[maxn][logn+5];
int a[maxn];//数组下标从1开始 
void makest(int n){
	for(int i = 1;i <= n;i++) st[i][0] = a[i];
	for(int j = 1;(1<<j) <= n;j++)
		for(int i = 1;i+(1<<j)-1 <= n;i++)
			st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
}
int query(int l, int r){
	int k = log(r-l+1)/log(2)+eps;
	return max(st[l][k], st[r-(1<<k)+1][k]);
}



