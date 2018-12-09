#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>
#include<string.h>
#include<queue>
#include<functional>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.siz()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define be begin
#define en end
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 10005;
const int INF = 0x3f3f3f3f;
struct Star {
	int next, to, l;
	void insert(int a, int b, int c) {
		to = a, l = b, next = c;
	}
}edge[maxn<<1];
int head[maxn], cnt = 0;
struct A{
	int q,flag;
}que[105];
int siz[maxn],dp[maxn], rt = 0, flag[maxn], d[maxn],deep[maxn],N;
int getroot(int x,int fa){
	siz[x] = 0,dp[x] = 1;
	for(int i = head[x];i != -1;i = edge[i].next){
		int to = edge[i].to;
		if(to == fa || flag[to])
			continue;
		dp[x] += getroot(to,x);
		siz[x] = max(siz[x], dp[to]);
	}
	siz[x] = max(siz[x], N-dp[x]);
	if(siz[rt] > siz[x]) 
		rt = x;
	return dp[x];
}
void getdeep(int x,int fa){
	d[++cnt] = deep[x];
	for(int i = head[x];i != -1;i = edge[i].next){
		int to = edge[i].to;
		if(to == fa || flag[to])
			continue;
		deep[to] = deep[x] + edge[i].l;
		getdeep(to, x);
	}
}
void calc(int x,int m,int t){
	cnt = 0;
	getdeep(x, 0);
	sort(d + 1, d + cnt + 1);
	for(int k = 1;k <= m;k++){
		for(int i = 1,j = cnt;i < j;){
			if(d[i]+d[j] < que[k].q) i++;
			else if(d[i]+d[j] > que[k].q) j--;
			else if(d[i] == d[j]){
				que[k].flag += ((j-i)*j/2)*t;
				break;
			}
			else{
				int x = i,y = j;
				while(d[x] == d[i])i++;
				while(d[y] == d[j])j--;
				que[k].flag += ((i - x)*(j - y))*t;
			}
		}
	}
}
void dfs(int x,int n,int m){
	deep[x] = 0;
	flag[x] = true;
	calc(x,m,1);
	for(int i = head[x];i != -1;i = edge[i].next){
		int to = edge[i].to;
		if(flag[to])
			continue;
		deep[to] = edge[i].l;
		calc(to,m,-1);
		N = dp[to];
		rt = 0;
		getroot(to, 0);
		dfs(rt, n, m);
	}
}
void solve(int n,int m){
	memset(flag, 0, sizeof flag);
	rt = 0,N = n,siz[0] = INF;
	getroot(1,0);
	dfs(rt, n, m);
	for(int i = 1;i <= m;i++)
		if(que[i].flag)
			printf("AYE\n");
		else
			printf("NAY\n");
	printf(".\n");
}
int main()
{
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	int n;
	while (~scanf("%d", &n)) {
		if (n == 0)
			break;
		N = n;
		memset(head, -1, sizeof head);
		cnt = 0;
		for (int i = 1;i <= n;i++) {
			int x,l;
			while(scanf("%d", &x)){
				if(x == 0)
					break;
				scanf("%d", &l);
				edge[++cnt].insert(i, l, head[x]);
				head[x] = cnt;
				edge[++cnt].insert(x, l, head[i]);
				head[i] = cnt;
			}
		}
		int m = 0, t;
		while(~scanf("%d", &t)){
			if(t == 0)
				break;
			que[++m].q = t;
			que[m].flag = 0;
		}
		 solve(n, m);
	}
	return 0;
}
