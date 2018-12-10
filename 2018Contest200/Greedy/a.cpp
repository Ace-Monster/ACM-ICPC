#include<iostream>
#include<vector>
#include<algorithm>
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
ll d[50005];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	ll r, l = 0, n, m;
	cin >> r >> n >> m;
	if(n == m) return cout << r << endl, 0;
	rep(i, 1, n + 1)
		cin >> d[i];
	d[n + 1] = r;
	sort(d + 1, d + n + 1);
	r*=2;
	ll mid = (l + r) / 2;
	ll sum = 0;
	while (l < r - 1) {
		sum = 0;
		ll q = 0;
		rep(i, 1, n + 2)
			if (d[i] - d[q] < mid){
				sum++;
				if(sum > m)
					break;
			}
			else q = i;
		if (sum <= m) l = mid;
		else r = mid;
		mid = (l + r) / 2;
	}
	cout << l << endl;
	return 0;
}
