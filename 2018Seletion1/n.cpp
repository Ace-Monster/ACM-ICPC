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
const int mod = 1e9+7;
long long fpower(long long a, long long b){
	long long sum = 1;
	while(b){
		if(b&1)
			sum = (sum*a)%mod;
		a = (a*a)%mod;
		b>>=1;
	}
	return sum%mod;
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	long long n;
	cin >> n;
	if(n == 1) return cout << 1 << endl, 0;
	if(n == 2) return cout << 10 << endl, 0;
	long long t1 = fpower(2, n-3);
	ll t2 = (t1*2)%mod, t3 = (t1*4)%mod;
	cout << ((((((t1*n)%mod)*(n-1))%mod)*(n-2))%mod + (((((3*t2)%mod)*n)%mod)*(n-1))%mod + (t3*n)%mod)%mod << endl;
	return 0;
}
