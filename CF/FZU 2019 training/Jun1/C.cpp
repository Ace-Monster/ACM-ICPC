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
const int maxn = 100005;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9;
ll a[maxn], sum[maxn<<1];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n;
	cin >> n;
	ll tans = 0, ans = 0;
	rep(i, 1, n+1){
		cin >> a[i];
		sum[i] = sum[i-1]+a[i];
	}
	map<ll, ll> q;
	rep(i, 1, n+1){
		q[sum[i]]++;
		ans = max(ans, q[sum[i]]);
	}
	cout << n - ans << endl;
	return 0;
}


