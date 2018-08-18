#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>
#include<string.h>
#include<queue>
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
int s[500005];
bool check(int n, ll mid, int sum, int m){
	rep(i, 1, n+2){
		if(s[i] - s[i-1] > mid)
			return false;
	}
	if(sum > m)return false;
	return true;
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	ll L,n,m;
	s[0] = 0;
	while(cin >> L >> n >> m){
		int mi = 0;
		for(int i = 1;i <= n;i++)
			cin >> s[i];
		s[n+1] = L;
		sort(s, s+n+1);
		for(int i = 1;i <= n+1;i++)
			mi = max(mi, s[i]-s[i-1]);
		ll l = 0, r = 2*L;
		ll mid = (l+r)/2;
		while(r - l > 1){
			int sum = 1,ti = 0;
			for(int i = 1;i <= n+1;i++){
				if(s[i] - s[ti] > mid){
					sum++;
					ti = i-1;
					if(sum > m) break;
				}
			}
			if(check(n, mid, sum, m))r = mid;
			else l = mid;
			mid = (l+r)/2;
		}
		cout << r << endl;
	}
	return 0;
}
