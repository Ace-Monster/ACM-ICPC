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
int a[maxn],b[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	ll n,m;
	cin >> n >> m;
	ll ans = n*n;
	ll A = 0, B = 0;
	rep(i, 0, m){
		int x,y;
		cin >> x >> y;
		if(!a[x]) a[x] = 1, A++;
		if(!b[y]) b[y] = 1, B++;
		//dd(A), de(B);
		cout << ans - n*A - n*B + A*B << ' ';
	}
	
	return 0;
}


