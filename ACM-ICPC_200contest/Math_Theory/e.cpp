#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>
#include<string.h>
#include<queue>
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
ll extgcd(ll a, ll b, ll &x, ll &y){
	ll d = a;
	if(b != 0){
		d = extgcd(b, a%b, y, x);
		y -= (a/b) * x;
	}
	else{
		x = 1, y = 0;
	}
	return d;
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	ll x, y, m, n, l;
	ll t,z;
	cin >> x >> y >> m >> n >> l;
	ll gcd = extgcd(m-n, l, t, z);
	if(((y-x)%gcd) != 0 || m == n) cout << "Impossible" << endl;
	else {
		ll dl = abs(l/gcd);
		t = t*((y-x)/gcd);
		t = (t % dl + dl) % dl;
		cout << t << endl;
	}
	return 0;
}
