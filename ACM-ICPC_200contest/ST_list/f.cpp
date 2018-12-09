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
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define be begin
#define en end
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 50000;
struct Star{
	int next,to;
}edge[maxn<<2];
int head[maxn+5],cnt = 0;
int f[maxn+5],query[maxn+5];
struct Task{
	int b,e,id;
	Task(int a,int be,int c):b(a),e(be),id(c) { }
};
vector<Task> task[maxn+5];
vector<pair<int,int> > v[maxn+5];
int mx[maxn+5],mi[maxn+5],up[maxn+5],down[maxn+5];
int find(int x){
	if(f[x] == x) return x;
	int y = f[x];
	f[x] = find(y);
	up[x] = max(mx[y]-mi[x],max(up[x],up[y]));
	down[x] = max(mx[x]-mi[y], max(down[x],down[y]));
	mx[x] = max(mx[x],mx[y]);
	mi[x] = min(mi[x],mi[y]);
	return f[x];
}
bool flag[maxn+5];
void lca_tarjan(int u){
	flag[u] = true;
	vector<pair<int,int> >::iterator it = v[u].be();
	for(;it != v[u].en();it++){
		if(flag[(*it).fi]){
			int t = find((*it).fi);
			if((*it).se > 0)
				task[t].pb(Task((*it).fi, u, (*it).se));
			else{
				task[t].pb(Task(u, (*it).fi, -(*it).se));
			}
		}
	}
	for(int i = head[u];i != -1;i = edge[i].next){
		if(!flag[edge[i].to]){
			lca_tarjan(edge[i].to);
			f[edge[i].to] = u;
		}
	}
	vector<Task>::iterator at = task[u].be();
	for(;at != task[u].en();at++){
		int x = at->b,y = at->e,id = at->id;
		find(x),find(y);
		query[id] = max(mx[y]-mi[x],max(up[x],down[y]));
	}
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	scanf("%d", &n);
	memset(head, -1, sizeof head);
	for(int i = 1;i <= n;i++){
		int w;
		scanf("%d", &w);
		f[i] = i;
		mi[i] = mx[i] = w;
	}
	for(int i = 1;i < n;i++){
		int x,y;
		scanf("%d%d", &x, &y);
		edge[++cnt].to = y;
		edge[cnt].next = head[x];
		head[x] = cnt;
		edge[++cnt].to = x;
		edge[cnt].next = head[y];
		head[y] = cnt;
	}
	int q;
	scanf("%d", &q);
	for(int i = 1;i <= q;i++){
		int x,y;
		scanf("%d%d", &x, &y);
		v[x].pb(mp(y,-i));
		v[y].pb(mp(x,i));
	}
	lca_tarjan(1);
	for(int i = 1;i <= q;i++)
		printf("%d\n", query[i]);
	return 0;
}
