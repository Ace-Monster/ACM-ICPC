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
const int maxn = 500005;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9;
ll a[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	ll n, k;
	cin >> n >> k;
	ll sum = 0;
	rep(i, 0, n){
		cin >> a[i];
		sum += a[i];
	}
	ll sum1 = sum/n;
	ll sum2 = ceil((ld)sum/(ld)n);
	sort(a, a+n);
	//rep(i, 0, n)
	//	cout << a[i] << ' ';
	//cout << endl;
	ll q = 0;
	ll mi = 0;
	rep(i, 0, n){
		if(a[i+1] >= sum1){
			ll t = (i+1)*(sum1-a[i]);
			if(q+t > k)
				mi = (k-q)/(i+1)+a[i];
			else
				mi = sum1;
			break;
		}
		ll t = (i+1)*(a[i+1]-a[i]);
		if(q+t > k){
			mi = (k-q)/(i+1)+a[i];
			break;
		}
		q+=t;
	}
	q = 0;
	ll ma = 0;
	for(int i = n-1;i >= 0;i--){
		if(a[i-1] <= sum2){
			ll t = (n-i)*(a[i] - sum2);
			if(q+t > k)
				ma = a[i] - (k-q)/(n-i);
			else
				ma = sum2;
			break;
		}
		ll t = (n-i)*(a[i] - a[i-1]);
		if(q+t > k){
			ma = a[i] - (k-q)/(n-i);
			break;
		}
		q+=t;
	}
	//dd(sum),dd(sum1),de(sum2);
	//dd(ma),de(mi);
	cout << ma-mi << endl;
	return 0;
}


