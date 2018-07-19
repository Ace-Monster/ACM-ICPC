#include<iostream>
#include<vector>
#include<string.h>
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
const ll mod = 2147493647;
struct M {
	int n, m;
	ll a[10][10];
	M(int t) {
		rep(i, 0, 7) {
			rep(j, 0, 7)
				a[i][j] = 0;
		}
		a[0][0] = a[0][2] = a[1][0] = a[2][2] = a[2][6] = 1;
		a[3][6] = a[4][6] = a[5][6] = a[6][6] = 1;
		a[3][3] = a[4][4] = a[5][5] = a[6][6] = 1;
		a[2][3] = a[2][5] = 4;
		a[2][4] = 6;
		a[3][4] = a[3][5] = 3;
		a[0][1] = a[4][5] = 2;
			/*a = {{ 1,2,1,0,0,0,0 },
					{ 1,0,0,0,0,0,0 },
					{ 0,0,1,4,6,4,1 },
					{ 0,0,0,1,3,3,1 },
					{ 0,0,0,0,1,2,1 },
					{ 0,0,0,0,0,1,1 },
					{ 0,0,0,0,0,0,1 }};*/
	}
	M()
	{
		memset(a, 0, sizeof(a));
	}
	const M operator*(const M &x) {
		M b;
		b.n = n, b.m = x.m;
		rep(i, 0, n)
			rep(j, 0, x.m)
		{
			rep(k, 0, m) {
				b.a[i][j] += ((a[i][k] % mod) * (x.a[k][j] % mod)) % mod;
			}
			b.a[i][j] %= mod;
		}
		return b;
	}
};
M mulit(M a, ll b) {
	M ant;
	ant.n = 7, ant.m = 7;
	rep(i, 0, 7)
		ant.a[i][i] = 1;
	while (b) {
		if (b & 1)
			ant = ant * a;
		a = a * a;
		b >>= 1;
	}
	return ant;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		M x(1);
		x.n = 7, x.m = 7;
		ll a, b, n;
		cin >> n >> a >> b;
		if (n == 1) { cout << a << endl;continue; }
		if (n == 2) { cout << b << endl;continue; }
		M g;
		g.n = 7, g.m = 1;
		g.a[0][0] = b,
			g.a[1][0] = a,
			g.a[2][0] = 81,
			g.a[3][0] = 27,
			g.a[4][0] = 9,
			g.a[5][0] = 3,
			g.a[6][0] = 1;
		g = mulit(x, n - 2)*g;
		cout << g.a[0][0] << endl;
	}
	return 0;
}
