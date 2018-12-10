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
const int maxn = 1e9;
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	ll n,m,k;
	cin >> n >> m >> k;
	if(k <= n-1){
		printf("%lld 1\n", k+1);
	}
	else{
		k -= n;
		ll h = n - k/(m-1);
		ll l = 0;
		if((n-h)&1) l = m - (k%(m-1));
		else l = (k%(m-1)) + 2;
		printf("%lld %lld\n", h, l);
	}
	return 0;
}
