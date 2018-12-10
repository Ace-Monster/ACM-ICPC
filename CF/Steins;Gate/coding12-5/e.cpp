#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 300005;
const ll inf = 0x3f3f3f3f3f3f3f;
ll a[maxn];
struct A{
	int to, next;
}edge[maxn<<1];
int head[maxn],cnt = 0;
void add(int x,int y){
	edge[cnt].to = y;
	edge[cnt].next = head[x];
	head[x] = cnt++;
}
bool flag[maxn];
ll maxnn = -inf;
ll dfs(int u){
	flag[u] = true;
	ll sum = a[u];
	for(int i = head[u];i != -1;i = edge[i].next){
		int v = edge[i].to;
		if(flag[v])
			continue;
		sum = max(sum, sum+dfs(v));
	}
	//dd(u),de(maxnn);
	maxnn = max(sum, maxnn);
	return sum;
}
ll ans = 0;
ll dfs2(int u){
	flag[u] = false;
	ll sum = a[u];
	for(int i = head[u];i != -1;i = edge[i].next){
		int v = edge[i].to;
		if(!flag[v])
			continue;
		sum = max(sum, sum+dfs2(v));
	}
	if(sum == maxnn){
		ans++;
		return -inf;
	}
	return sum;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	scanf("%d", &n);
	memset(head, -1, sizeof head);
	rep(i, 1, n+1)
		scanf("%lld", &a[i]);
	rep(i, 0, n-1){
		int x,y;
		scanf("%d %d", &x, &y);
		add(x, y);
		add(y, x);
	}
	dfs(1);
	//de(maxnn);
	dfs2(1);
	printf("%lld %lld\n", maxnn*ans, ans);
	return 0;
}
