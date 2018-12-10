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
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 100005;
const int logn = (log(maxn)/log(2))+1;
const int inf = 0x3f3f3f3f;
const ld eps = 1e-9;
const ll mod = 1e9;
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n;
	ll sum = 0;
	cin >> n;
	rep(i, 0, n){
		ll x;
		cin >> x;
		sum += (x-1);
		if(sum&1) cout << 1 << endl;
		else cout << 2 << endl;
	}
	return 0;
}


