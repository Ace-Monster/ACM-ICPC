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
ll extgcd(ll a, ll b, ll &x, ll &y){
	ll d = a;
	if(b){
		d = extgcd(b, a%b, y, x);
		y -= (a/b)*x;
	}
	else{
		x = 1, y = 0;
	}
	return d;
}
ll min_non(ll a, ll b, ll &x, ll &y){
	ll t = extgcd(a, b, x, y);
	if(t != 1) return -1;
	ll db = (b / t);
	x = ((x % db) + db) % db;
	y = (1 - a*x) / b;
	return t;
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	ll a, b;
	while(cin >> a >> b){
		ll x = 0, y = 0;
		ll t = min_non(a, b, x, y);
		if(t != 1) cout << "sorry" << endl;
		else{
			cout << x << ' ' << y << endl;
		}
	}
	return 0;
}
