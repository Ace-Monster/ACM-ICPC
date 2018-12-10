#include<iostream>
#include<stack>
#include<vector>
#include<cstdio>
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
struct Star {
	int to, next;
}edge[50000];
int head[1000], match[1000];
bool flag[1000];
bool find(int u) {
	for (int i = head[u];i != -1;i = edge[i].next) {
		int to = edge[i].to;
		if (!flag[to]) {
			flag[to] = true;
			if (match[to] == 0 || find(match[to])) {
				match[to] = u;
				return true;
			}
		}
	}
	return false;
}
int hungarian(int n, int m) {
	int sum = 0;
	for (int i = 1;i <= n;i++) {
		if (find(i))
			sum++;
		memset(flag, 0, sizeof flag);
	}
	return sum;
}
int main()
{
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m;
		int cnt = 0;
		scanf("%d%d", &n, &m);
		memset(match, 0, sizeof match);
		memset(edge, 0, sizeof edge);
		memset(head, -1, sizeof head);
		int maxx = 0;
		for (int i = 1;i <= n;i++) {
			int t;
			scanf("%d", &t);
			for (int j = 0;j < t;j++) {
				int x;
				scanf("%d", &x);
				maxx = max(x,maxx);
				edge[++cnt].to = i;
				edge[cnt].next = head[x];
				head[x] = cnt;
			}
		}
		if (hungarian(maxx, m) == n)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
