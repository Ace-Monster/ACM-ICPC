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
const int maxn = 200005;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9;
pair<ll, ll> poi[maxn];
map<pair<ll, ll>, ll> flag;
map<ll, ll> x, y;
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n;
	cin >> n;
	rep(i, 0, n){
		cin >> poi[i].fi >> poi[i].se;
		flag[poi[i]]++;
		x[poi[i].fi]++;
		y[poi[i].se]++;
	}
	ll ans = 0;
	for(auto i : flag){
		ans -= i.se*(i.se-1)/2;
	}
	for(auto i : x){
		ans += i.se*(i.se-1)/2;
	}
	for(auto i : y){
		ans += i.se*(i.se-1)/2;
	}
	cout << ans << endl;
	return 0;
}


