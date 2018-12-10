#include<iostream>
#include<vector>
#include<cstdio>
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
const int inf = 0x3f3f3f3f;
struct A {
	int to, cost;
	A(int a, int b) :to(a), cost(b) { }
};
int d[105];
int l[105], v[105];
//bool u[105];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int m, n;
	while (cin >> m >> n) {
		vector<A> edge[105];
		for (int i = 1;i <= n;i++) {
			int x;
			cin >> v[i] >> l[i] >> x;
			rep(j, 0, x) {
				int a, b;
				cin >> a >> b;
				edge[i].pb(A(a, b));
			}
		}
		//memset(u, 0, sizeof(u));
		int mi = inf;
		for (int k = l[1] - m;k <= l[1];k++) {
			memset(d, inf, sizeof(d));
			d[1] = 0;
			/*
			while (true) {
				int V = -1;
				for (int i = 1;i <= n;i++) {
					if(l[i] < k || l[i] > k+m)
						continue;
					if (!u[i] && (V == -1 || d[i] < d[V]))
						V = i;
				}
				if (V == -1)
					break;
				u[V] = true;
				vector<A>::iterator it = edge[V].be();
				for (;it != edge[V].en();it++) {
					if(l[(*it).to] < k || l[(*it).to] > k+m)
						continue;
					d[(*it).to] = min(d[(*it).to], d[V] + (*it).cost);
				}
			}*/
			priority_queue<pii, vector<pii>,greater<pii> > q;
			q.push(mp(0, 1));
			while(q.size()){
				pii p = q.top();
				q.pop();
				int v = p.se;
				if(d[v] < p.fi) continue;
				vector<A>::iterator it;
				for(it = edge[v].be();it != edge[v].en();it++){
					if(l[(*it).to] < k || l[(*it).to] > k+m) continue;
					if(d[(*it).to] > d[v]+(*it).cost){
						d[(*it).to] = d[v] + (*it).cost;
						q.push(mp(d[(*it).to], (*it).to));
					}
				}
			}
			for (int i = 1;i <= n;i++) {
				mi = min(mi, d[i] + v[i]);
			}
		}
		cout << mi << endl;
	}
	return 0;
}
