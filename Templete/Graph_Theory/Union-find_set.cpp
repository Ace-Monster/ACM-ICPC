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
