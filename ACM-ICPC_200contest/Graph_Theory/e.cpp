#include<cstdio>
#include<iostream>
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
int maps[1005][1005];
int s[1005];
const int inf = 0x3f3f3f3f;
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int T;
	scanf("%d", &T);
	for(int k = 1;k <= T;k++){
		memset(s, 0, sizeof s);
		memset(maps, -1, sizeof maps);
		s[1] = inf;
		int n,m;
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= m;i++){
			int x,y,t;
			scanf("%d%d%d", &x, &y, &t);
			maps[x][y] = maps[y][x] = t;
		}
		priority_queue<pii,vector<pii>,less<pii> > q;
		q.push(mp(inf, 1));
		while(!q.empty()){
			pii p = q.top();
			q.pop();
			if(s[p.se] > p.fi) continue;
			for(int i = 1;i <= n;i++){
				if(s[i] < min(s[p.se], maps[p.se][i])){
					s[i] = min(s[p.se], maps[p.se][i]);
					q.push(mp(s[i], i));
				}
			}
		}
		printf("Scenario #%d:\n%d\n\n", k, s[n]);
	}
	return 0;
}
