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
const int maxn = 500005;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9;
char s[maxn];
ll sum[maxn<<1];
int n, a;
bool chk(int t, int l, int r){
	int ans = 0;
	if(r <= n) ans = r-l;
	else ans = r-l+min(n-l+1, r-n-1);
	return sum[r]-sum[l-1]+ans*a <= t;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int b,t;
	cin >> n >>a >> b >> t;
	scanf("%s", s+1);
	int w = 0, h = 0; 
	rep(i, 1, n+1){
		sum[i] = sum[i-1];
		sum[i] += 1 + (s[i] == 'w' ? b : 0);
	}
	rep(i, 1, n+1){
		sum[i+n] = sum[i-1+n];
		sum[i+n] += 1 + (s[i] == 'w' ? b:0);
	}
	int ans = 0;
	rep(i, 1, n+1){
		int l = i-1, r = i+n-1, mid = (l+r)>>1;
		while(r-l>1){
			if(chk(t, i, mid)) l = mid;
			else r = mid;
			mid = (l+r)>>1;
		}
		if(chk(t, i, r)) r = r;
		else if(chk(t, i, mid)) r = mid;
		else r = l;
		//dd(i),dd(r),de(r-i+1);
		if(i == 1 || r > n)
			ans = max(ans, r-i+1);
	}
	cout << ans << endl;
	return 0;
}
/*
4 2 3 10
wwhw

*/

