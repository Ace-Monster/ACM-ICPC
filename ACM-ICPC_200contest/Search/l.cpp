#include<iostream>
#include<cstdio>
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
char maps[15][15];
int flag[15][15];
int xi[4] = { 0,1,0,-1 };
int yi[4] = { 1,0,-1,0 };
int n, m;
struct A {
	int x, y, sum;
	A(int a, int b, int c) :x(a), y(b), sum(c) { }
};
int bfs(int x, int y, int xx = -1, int yy = -1) {
	int f = flag[x][y];
	int ff[15][15];
	memset(ff, 0, sizeof(ff));
	queue<A> q;
	q.push(A(x, y, 0));
	ff[x][y] = 1;
	if (xx != -1)
		ff[xx][yy] = 1, q.push(A(xx, yy, 0));
	int sum = 0;
	while (!q.empty()) {
		sum = q.front().sum;
		int ttx = q.front().x, tty = q.front().y;
		q.pop();
		rep(i, 0, 4) {
			int tx = ttx + xi[i], ty = tty + yi[i];
			if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
			if (flag[tx][ty] != f) continue;
			if (ff[tx][ty]) continue;
			q.push(A(tx, ty, sum + 1));
			ff[tx][ty] = 1;
		}
	}
	return sum;
}
int main()
{
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	int T;
	scanf("%d", &T);
	int t = 0;
	while (T--) {
		printf("Case %d: ", ++t);

		memset(flag, 0, sizeof(flag));
		scanf("%d%d", &n, &m);
		getchar();
		rep(i, 0, n) {
			rep(j, 0, m)
				scanf("%c", &maps[i][j]);
			getchar();
		}
		queue<pair<int, int> > q;
		int sum = 0;
		rep(i, 0, n)
			rep(j, 0, m) {
			if (maps[i][j] == '#' && flag[i][j] == 0)
				flag[i][j] = ++sum, q.push(mp(i, j));
			if (sum >= 3) break;
			while (!q.empty()) {
				int ttx = q.front().fi, tty = q.front().se;
				q.pop();
				rep(k, 0, 4) {
					int tx = ttx + xi[k], ty = tty + yi[k];
					if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
					if (maps[tx][ty] != '#') continue;
					if (flag[tx][ty]) continue;
					flag[tx][ty] = sum;
					q.push(mp(tx, ty));
				}
			}
		}
		if (sum >= 3) {
			printf("%d\n", -1);
			continue;
		}
		int sum1 = 1e9, sum2 = 1e9;
		if (sum == 1) {
			rep(i1, 0, n) {
				rep(j1, 0, m) {
					if (flag[i1][j1]) {
						rep(i2, i1, n) {
							int j2 = 0;
							if(i2 == i1)
								j2 = j1;
							for(;j2 < m;j2++) {
								if (maps[i2][j2] == '#')
									sum1 = min(sum1, bfs(i1, j1, i2, j2));
							}
						}
					}
				}
			}
		}
		if (sum == 2) {
			rep(i, 0, n)
				rep(j, 0, m) {
				if (flag[i][j] == 1)
					sum1 = min(sum1, bfs(i, j));
				if (flag[i][j] == 2)
					sum2 = min(sum2, bfs(i, j));
			}
			sum1 = max(sum1, sum2);
		}
		if (sum == 0) sum1 = 0;
		printf("%d\n", sum1);
	}
	return 0;
}
