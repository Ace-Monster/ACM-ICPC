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
int a[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n;
	cin >> n;
	int m = inf;
	int ans = 0;
	rep(i, 0, n){
		cin >> a[i];
		ans += a[i];
		m = min(a[i], m);
	}
	int tans = ans;
	rep(i, 0, n){
		if(a[i] == m)
			continue;
		for(int j = 2;j*j <= a[i];j++){
			if(a[i]%j == 0){
				ans = min(ans, tans-a[i]+a[i]/j-m+m*j);
			}
				
		}
	}
	cout << ans << endl;
	return 0;
}


