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
#define mem(a, b) memset(a, b, sizeof a)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 200005;
int a[maxn], ans[maxn];
struct Star{
	int to,next;
}edge[maxn<<1];
int head[maxn], cnt;
int gcd(int a, int b){
	if(b)
		return gcd(b, a%b);
	return a;
}
void dfs(int f, int u, set<int> q, int val){
	set<int> p;
	p.insert(val);
    //de(q.size());
	for(auto it = q.begin();it != q.end();it++){
		p.insert(gcd(*it, a[u]));
	}
    val = gcd(val, a[u]);
	ans[u] = *p.rbegin();
	for(int i = head[u];i != -1;i = edge[i].next){
        if(edge[i].to == f)
            continue;
		dfs(u, edge[i].to, p, val);
	}
}
void add(int x, int y){
	edge[++cnt].next = head[x];
	edge[cnt].to = y;
	head[x] = cnt;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
    mem(head, -1);
    //de(Gcd(6, 2));
	int n;
	scanf("%d", &n);
	rep(i, 1, n+1)
		scanf("%d", &a[i]);
	rep(i, 1, n){
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
        add(y, x);
	}
	set<int> q;
	q.insert(0);
	dfs(0, 1, q, 0);
    //cout << q.size() << endl;
	rep(i, 1, n+1){
		printf("%d%c", ans[i], i == n ? '\n':' ');
	}
	return 0;
}
