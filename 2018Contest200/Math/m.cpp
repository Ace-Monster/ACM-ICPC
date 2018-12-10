#include<map>
#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
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
inline ll gcd(ll a, ll b) {
	if (b) return gcd(b, a%b);
	return a;
}
inline ll solve(ll x, ll y, vi pi) {
	ll n = pow(2, pi.size());
	vi::iterator it = pi.be();
	ll sum = 0;
	for (ll m = 1;m < n;m++) {
		ll i = m;
		it = pi.be();
		ll p = 1,t = 0;
		while (i) {
			if (i % 2) {
				p *= (*it);
				t++;
			}
			i >>= 1;
			it++;
		}
		ll xi = ceil((double)x / p), yi = floor((double)y / p);
		if (t % 2)
			sum += (yi*(yi + 1) / 2 - (xi * (xi - 1)) / 2)*p;
		else
			sum -= (yi*(yi + 1) / 2 - (xi * (xi - 1)) / 2)*p;
	}
	return sum;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		ll n, m;
		scanf("%lld%lld", &n, &m);
		map<ll, ll> a;
		while (m--) {
			ll t, x, y, pis;
			scanf("%lld%lld%lld", &t, &x, &y);
			if (t == 1) {
				scanf("%lld", &pis);
				ll p = pis;
				vi pi;
				int i;
				for (i = 2;i * i <= p;i++) {
					if (p % i == 0) pi.pb(i);
					while (p % i == 0) p /= i;
				}
				if (p != 1) pi.pb(p);
				ll sum = y * (y + 1) / 2 - x * (x - 1) / 2 - solve(x, y, pi);
				map<ll, ll>::iterator at;
				for (at = a.be();at != a.en();at++) {
					if(at->fi < x) continue;
					if(at->fi > y) break;
					if (gcd(at->fi, pis) == 1)
						sum -= at->fi;
					if (gcd(at->se, pis) == 1)
						sum += at->se;
				}
				printf("%lld\n", sum);
			}
			else
				a[x] = y;
		}
	}
	return 0;
}
