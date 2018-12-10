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
const int maxn = 30000, maxm = 150000;
struct Star {
	int next, to;
}maps[maxm + 5], edge[maxm + 5];
int v[maxn + 5], w[maxn + 5], head[maxn + 5], cnt, head2[maxn + 5];
int dfn[maxn + 5], low[maxn + 5], gra[maxn + 5];
stack<int> q;
void tarjan(int u) {
	dfn[u] = low[u] = ++cnt;
	q.push(u);
	for (int i = head[u]; i != -1;i = maps[i].next) {
		if (dfn[maps[i].to] == 0) {
			tarjan(maps[i].to);
			low[u] = min(low[u], low[maps[i].to]);
		}
		else if (gra[maps[i].to] == 0)
			low[u] = min(low[u], dfn[maps[i].to]);
	}
	if (dfn[u] == low[u]) {
		int tu;
		do {
			tu = q.top();
			q.pop();
			gra[tu] = low[u];
		} while (tu != u);
	}
	return;
}
int spfa(int n) {
	int ans = 0;
	int d[maxn + 5];
	bool flag[maxn + 5];
	memset(d, 0, sizeof d);
	memset(flag, 0, sizeof flag);
	for (int i = 1;i <= n;i++) {
		if (gra[i] != 0 && flag[gra[i]] == 0) {
			d[gra[i]] = max(d[gra[i]], w[gra[i]]);
			flag[gra[i]] = 1;
			ans = max(d[gra[i]], ans);
			queue<int> p;
			p.push(gra[i]);
			while (p.size()) {
				int t = p.front();
				p.pop();
				for (int j = head2[t];j != -1;j = edge[j].next)
					if (d[edge[j].to] < d[t] + w[edge[j].to]) {
						d[edge[j].to] = d[t] + w[edge[j].to];
						ans = max(ans, d[edge[j].to]);
						p.push(edge[j].to);
					}
			}
		}
	}
	return ans;

}
int main()
{
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	int n, m;
	while (~scanf("%d%d", &n, &m)) {
		cnt = 0;
		memset(gra, 0, sizeof gra);
		memset(head, -1, sizeof head);
		memset(dfn, 0, sizeof dfn);
		for (int i = 1;i <= n;i++)
			scanf("%d", &v[i]);
		for (int i = 1;i <= m;i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			maps[i].next = head[x + 1];
			maps[i].to = y + 1;
			head[x + 1] = i;
		}
		for (int i = 1;i <= n;i++) {
			if (gra[i] == 0)
				tarjan(i);
		}
		memset(w, 0, sizeof w);
		memset(head2, -1, sizeof head2);
		cnt = 0;
		for (int i = 1;i <= n;i++) {
			if (v[i] > 0)
				w[gra[i]] += v[i];
			for (int j = head[i];j != -1;j = maps[j].next) {
				if (gra[i] == gra[maps[j].to])
					continue;
				edge[++cnt].next = head2[gra[i]];
				edge[cnt].to = gra[maps[j].to];
				//dfn[gra[i]]++;
				head2[gra[i]] = cnt;
			}
		}
		printf("%d\n", spfa(n));
	}
	return 0;
}
