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
const ll mod = 1000000007;
ll euler_phi(ll n){
	ll res = n;
	for(int i = 2;i *i <= n;i++){
		if(n%i == 0){
			res = res / i * (i - 1);
			for(;n % i == 0;n /= i);
		}
	}
	if(n != 1) res = res/n*(n-1);
	return res;
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	ll n;
	while(cin >> n){
		if(n == 0)break;
		ll sum = n*(n-1)/2;
		cout << (sum - (n*euler_phi(n))/2)%mod << endl;
	}
	return 0;
}
