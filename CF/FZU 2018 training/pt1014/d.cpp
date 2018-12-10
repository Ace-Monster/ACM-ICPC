#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<functional>
#include<stack>
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
ll a[maxn], b[maxn];
inline bool check(ll mid, ll n, ll k){
	for(int i = 1;i <= n;i++){
		ll s = mid*a[i];
		ll d = b[i] - s;
		if(d < 0) k += d;
		if(k < 0) return false;
	}
	return true;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	ll n, k;
	scanf("%lld%lld", &n, &k);
	for(int i = 1;i <= n;i++)
		scanf("%lld", &a[i]);
	for(int i = 1;i <= n;i++)
		scanf("%lld", &b[i]);
	ll l = 0, r = 1e10;
	ll mid = (l+r)>>1;
	while(r - l > 1){
		if(check(mid, n, k)) l = mid;
		else r = mid;
		//dd(l),dd(r),de(mid);
		mid = (l+r)>>1;
	}
	ll ans;
	if(check(r, n, k)) ans = r;
	else if(check(mid, n, k)) ans = mid;
	else ans = l;
	printf("%lld\n", ans);
	return 0;
}
