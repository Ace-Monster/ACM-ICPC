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
int a[200005];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n;
	cin >> n;
	rep(i, 0, n)
		cin >> a[i];
	ll ans = 0;
	ll sum = 0, xors = 0;
	sum += a[0], xors ^= a[0];
	int l = 0, r = 0;
	for(;l < n;l++){
		if(sum == xors)
		{
			ll t = r - l;
			ans -= (t*(t+1))/2;
			r++;
			for(;r < n;r++){
				sum += a[r], xors ^= a[r];
				//cout << sum << ' ' << xors << endl;
				if(sum != xors){
					t = r - l;
					ans += (t*(t+1))/2;
					break;
				}
			}
		}
		if(r >= n){
			//cout << 1 << endl;
			break;
		}
		sum -= a[l], xors ^= a[l];
	}
	if(sum == xors){
		ll t = r - l;
		ans += (t*(t+1))/2;
	}
	cout << ans << endl;
	return 0;
}
