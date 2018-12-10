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
int a[30];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	if(n > 26)
		return cout << -1 << endl, 0;
	int ans = 0;
	rep(i, 0, n){
		a[s[i]-'a']++;
	}
	rep(i, 0, 30){
		if(a[i] >= 2) ans += a[i]-1;
	}
	cout << ans << endl;
	return 0;
}


