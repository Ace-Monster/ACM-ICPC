#include<bits/stdc++.h>
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
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 100005;
const int logn = (log(maxn) / log(2)) + 1;
const int inf = 0x3f3f3f3f;
const ld eps = 1e-9;
const ll mod = 1e9;
int x[maxn][105];
string s;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	cin >> n;
	cin >> s;
	int ans = inf;
	rep(i, 0, n) x[n][s[i] - 'A'] = -1;
	for (int i = n - 1;i >= 0;i--) {

		rep(j, 0, 100) x[i][j] = x[i + 1][j];
		x[i][s[i] - 'A'] = i;
		int r = -1, flag = 0;
		rep(j, 0, 100) {
			if (x[i][j] == -1) {
				flag = 1;
				break;
			}
			r = max(r, x[i][j]);
		}

		if (!flag) ans = min(ans, r - i + 1);
	}
	cout << ans << endl;
	return 0;
}


