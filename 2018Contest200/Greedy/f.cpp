#define _CRT_SECURE_NO_DEPRECATE 
#include<iostream>
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
struct A {
	int p, b;
	bool operator<(const A &x)const {
		return b < x.b;
	}
}a[105][105];
int mi[105];
double dfs(int n, int tl, int l, int p, int b, int cnt) {
	if (n == l) {
		return ((double)p / (double)b);
	}
	if ((double)p / (double)b < cnt)
		return 0;
	double sum = 0;
	if (l == tl)
		return dfs(n, tl, l + 1, p, b, cnt);
	for (int i = 0;i < mi[l];i++) {
		if (a[l][i].p < p)continue;
		sum = max(sum, dfs(n, tl, l + 1, p, b + a[l][i].b, cnt));
		return sum;
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
		int n;
		scanf("%d", &n);
		rep(i, 0, n) {
			cin >> mi[i];
			rep(j, 0, mi[i])
				scanf("%d%d", &a[i][j].p, &a[i][j].b);
			sort(a[i], a[i] + mi[i]);
		}
		double sum = 0;
		double pi = 0, b = 0;
		for (int i = 0;i < n;i++) {
			map<int, bool> flag;
			for (int j = 0;j < mi[i];j++) {
				if (flag[a[i][j].p]) continue;
				pi = a[i][j].p, b = a[i][j].b;
				flag[pi] = true;
				sum = max(dfs(n, i, 0, pi, b, sum), sum);
			}
		}
		printf("%.3lf\n", sum);
	}
	return 0;
}
