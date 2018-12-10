//线段树适合做 点更新+段查询、段更新+点查询
//对于其余情况使用线段树 

const int maxn = 100005;
#define lowbit(x) x&-x

//点更新+段查询，返回前缀和，b为前缀和数组 
int b[maxn], n; 
void add(int i, int t){//单点更新 
	for(;i <= n;b[i] += t,i += lowbit(i));
}
int query(int i){//返回查询点的前缀和 
	int sum;
	for(sum = 0;i >= 1;sum += b[i], i -= lowbit(i));
	return sum;
}


//段更新+点查询，返回查询点的值，c为差分数组
//query()与add()和点+段相同 
int c[maxn], n;
void add(int i, int t){
	for(;i <= n;c[i] += t,i += lowbit(i));
}
void range_add(int i, int l, int r){//区间更新 
	add(i, l);
	add(-i, r+1);
}
int query(int i){//返回查询点的值 
	int sum;
	for(sum = 0;i >= 1;sum += c[i], i -= lowbit(i));
	return sum;
}


//段更新+段查询，在同为差分数组的情况下，点查询(前缀和)公式为
// sum(i) = c[0]+(c[0]+c[1])+(c[0]+c[1]+c[2])+...+(c[0]+...+c[i])
//即 sum(i) = ∑(x=0, i) (i-x)*c[x]
//sum(i) = i*(c[1]+c[2]+...+c[i])-(0*c[1]+1*c[2]+...+(i-1)*c[i])
//所以维护两个差分数组，c1[i] = c[i],c2[i] = (i-1)*c[i]; 
int c1[maxn],c2[maxn],n;
int add(int t, int p){
	for(int i = p;i <= n;i += (i&-i)){
		c1[i] += t;
		c2[i] += (p-1)*t;
	}
}
int r_add(int l,int r,int t){
	add(t, l);
	add(-t, r+1);
}
int query(int p){
	int sum = 0;
	for(int i = p;i >= 1;i-=(i&-i)){
		sum += p*c1[i] - c2[i];
	}
	return sum;
}
int r_query(int l,int r){
	return query(r)-query(l-1);
}
