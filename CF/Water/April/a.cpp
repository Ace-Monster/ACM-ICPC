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
int ans = 0;
void solve(int l,int r){
	rep(i, l+1, r+1){
		if(a[i] < a[i-1]){
			int mid = (l+r)>>1;
			solve(l, mid);
			solve(mid+1, r);
			return;
		}
	}
	ans = max(ans, r-l+1);
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n;
	cin >> n;
	rep(i, 0, n)
		cin >> a[i];
	solve(0, n-1);
	cout << ans << endl;
	return 0;
}


