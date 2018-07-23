#include<iostream>
#include<vector>
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
//欧几里得求逆元 O(log(max(a, b)))
ll extgcd(ll a, ll b, ll &x, ll &y) {
	ll d = a;
	if (b != 0) {
		d = extgcd(b, a%b, y, x);
		y -= (a / b)*x;
	}
	else {
		x = 1; y = 0;
	}
	return d;
}
ll mod_inverse(ll a, ll m) {
	ll x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}
//费马小定理 O(log b)
ll pows(ll a, ll b, ll p){
	ll ans = 1;
	while(b != 0){
		if(b&1) ans = (ans * a)%p;
		a = (a*a)%p;
		b>>=1;
	}
	return ans;
}
ll C(ll n, ll m, ll p) {
	ll a1 = 1, a2 = 1, a3 = 1;
	for (ll i = 2; i <= m;i++) {
		a3 = (a3 * (i%p)) % p;
	}
	for(ll i = n - m + 1;i <= n;i++){
		a1 = (a1 * (i%p)) % p;
	}
	return (a1*mod_inverse(a3, p)) % p;
}
ll Lucas(ll n, ll m, ll p) {
	if (n < p && m < p)
		return C(n, m, p);
	return C(n % p, m % p, p)*Lucas(n / p, m / p, p);
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		ll n, m, p;
		cin >> n >> m >> p;
		cout << Lucas(n, m, p) << endl;
	}
	return 0;
}
