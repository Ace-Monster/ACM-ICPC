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
const ll mod = 9973;
ll first_pow(ll n){
	ll sum = 1;
	ll b = 9973 - 2;
	n%=mod;
	while(b){
		if(b&1) sum = (sum * n) % mod;
		n = (n*n)%mod;
		b>>=1;
	}
	return sum;
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		ll a,b;
		cin >> a >> b;
		cout << (a*first_pow(b))%mod << endl;
	}
	return 0;
}
