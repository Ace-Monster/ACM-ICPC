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
const int maxn = 100005;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9;
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	ll n,a,b,c,d;
	cin >> n >> a >> b >> c >> d;
	ll ans = 0;
	rep(i, 1, n+1){
		ll r = a+b+i;
		if(r-a-c > n || r-a-c<1) continue;
		if(r-c-d > n || r-c-d < 1) continue;
		if(r-b-d > n || r-b-d < 1) continue;
		ans += n;
	}
	cout << ans << endl;
	return 0;
}


