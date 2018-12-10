#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<functional>
#include<stack>
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
const int maxn = 200005;
struct Star{
	int to, next;
}edge[maxn<<1];
int head[maxn], dist[maxn], pre[maxn];
void dfs(int u, int d){
	dist[u] = d;
	for(int i = head[u];i != -1;i = edge[i].next){
		int to = edge[i].to;
		if(to == pre[u])
			continue;
		pre[to] = u;
		dfs(to, d+1);
	}
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	scanf("%d", &n);
	memset(head, -1, sizeof head);
	int cnt = 0;
	for(int i = 1;i < n;i++){
		int x,y;
		scanf("%d%d", &x, &y);
		edge[++cnt].to = x;
		edge[cnt].next = head[y];
		head[y] = cnt;
		edge[++cnt].to = y;
		edge[cnt].next = head[x];
		head[x] = cnt;
	}
	dfs(1, 0);
	set<pair<int, int> > q;
	for(int i = 1;i <= n;i++){
		if(dist[i] > 2)
			q.insert(mp(-dist[i], i));

	}
	set<pair<int, int> >::iterator it;
	int ans = 0;
	while(q.size()){
		ans++;
		int u = q.begin()->second;
		u = pre[u];
		q.erase(mp(-dist[u], u));
		for(int i = head[u];i != -1;i = edge[i].next){
			int to = edge[i].to;
			it = q.find(mp(-dist[to], to));
			if(it != q.end()) q.erase(it);
		}
	}
	printf("%d\n", ans);
	return 0;
}
