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
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 300005;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9;
int a[maxn];
vi q[2][maxn];
map<int, int> p[2];
int cnt[2];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n;
	cin >> n;
	int x = 0;
	rep(i, 1, n+1){
		cin >> a[i];
		x = x^a[i];
		//dd(i),de(x);
		if(!p[i&1][x]) p[i&1][x] = ++cnt[i&1];
		q[i&1][p[i&1][x]].pb(i);
	}
	q[0&1][p[0&1][0]].pb(0);
	ll ans = 0;
	rep(i, 0, 2){
		rep(j, 1, cnt[i&1]+1){
			ll t = sz(q[i&1][j]);
			//de(t);
			ans += t*(t-1)/2;
		}
	}
	cout << ans << endl;
	return 0;
}


