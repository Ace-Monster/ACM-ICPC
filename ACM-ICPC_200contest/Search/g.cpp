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
int dfs(int n, int l, int R, int H, int v, int cnt, int sum) {
	if (n == l) {
		if (v > 0) return cnt;
		if (cnt > sum) return sum;
		else return cnt;
	}
	for (int r = R-1;r > 0;r--) {
		for (int h = H-1;h > 0;h--) {
			int vis = r * r*h;
			if (vis > v) continue;
			int sumi = 2 *r*h;
			if (sum + sumi > cnt) continue;
			int mins = 0, maxs = 0;
			rep(k, 1, n - l) {
				mins += k * k*k;
				maxs += (r - k)*(r - k)*(h - k);
			}
			if (mins + vis > v)continue;
			if (maxs + vis < v)continue;
			cnt = dfs(n, l + 1, r, h, v - vis, cnt, sum + sumi);
		}
	}
	return cnt;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n, m;
	cin >> n >> m;
	int cnt = 1e11;
	for (int r = 100;r > 0;r--) {
		for (int h = 10000;h > 0;h--) {
			int vis = r * r*h;
			if (vis > n) continue;
			int sumi = r * r + 2 * r*h;
			if (sumi > cnt) continue;
			int mins = 0, maxs = 0;
			rep(k, 1, m) {
				mins += k * k*k;
				maxs += (r - k)*(r - k)*(h - k);
			}
			if (mins + vis > n)continue;
			if (maxs + vis < n)continue;
			cnt = dfs(m, 1, r, h, n - vis, cnt, sumi);
		}
	}
	cout << cnt << endl;
	return 0;
}
