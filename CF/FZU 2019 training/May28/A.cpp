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
int chg(int &a, int &b){
	int t = ceil((double)a/2.0)-1;
	a -= 2*t;
	b += t;
	return t;
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int a,b;
	cin >> a >> b;
	if(a == 1 && b == 1){
		cout << 0 << endl;
		return 0;
	}
	int ans = 0;
	while(a > 2 || b > 2){
		ans += (a>b ? chg(a,b) : chg(b, a));
	}
	if(a&&b) ans ++;
	cout << ans << endl;
	return 0;
}


