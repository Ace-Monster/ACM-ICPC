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
const int mod = 1e9+7;
int a[100005], b[100005];
long long c[100005];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n, k;
	cin >> n >> k;
	int maxbi = 0;
	rep(i, 0, n)
		cin >> a[i];
	rep(i, 0, k)
	{
		if(!b[a[i]])
			maxbi++;
		b[a[i]]++;
	}
	int tmaxbi = maxbi;
	rep(i, k, n){
		b[a[i-k]]--;
		if(!b[a[i - k]]) tmaxbi--;
		if(!b[a[i]])
			tmaxbi++;
		b[a[i]]++;
		maxbi = max(maxbi, tmaxbi);
	}
	memset(b, 0, sizeof b);
	tmaxbi = maxbi;
	rep(i, 0, k){
		if(!b[a[i]])
			c[i] = tmaxbi--;
		else
			c[i] = 1;
		b[a[i]]++;
	}
	rep(i, k, n){
		b[a[i - k]]--;
		if(!b[a[i - k]]) tmaxbi++;
		if(!b[a[i]]) c[i] = tmaxbi--;
		else c[i] = 1;
		b[a[i]]++;
	}
	long long sum = 1;
	rep(i, 0, n)
		sum = (sum * c[i])%mod;
	cout << sum << endl;
	return 0;
}
