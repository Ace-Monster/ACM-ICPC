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
#define be begin
#define en end
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll xi[2005], yi[2005], d[2005][2005], v[2005];
bool cmp(ll a,ll b){
	return a>b;
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n;
	cin >> n;
	rep(i, 0, 2*n){
		cin >> xi[i] >> yi[i];
	}
	rep(i, 0, 2*n){
		d[i][i] = 0;
		rep(j, i + 1, 2*n){
			ll dx = xi[i] - xi[j];
			ll dy = yi[i] - yi[j];
			d[i][j] = (dx*dx)+(dy*dy);
			d[j][i] = d[i][j];
		}
	}
	//rep(i, 0, 2*n){
	//	rep(j, 0, 2*n)
	//		cout << d[i][j] << ' ';
	//	cout << endl;
	//}
	rep(i, 0, 2*n){
		rep(j, 0, 2*n)
			v[i] += d[i][j];
	}
	ll sum = 0;
	//rep(i, 0, 2*n)
	//	cout << v[i] << ' ';
	//cout << endl;
	sort(v, v+(2*n), cmp);
	for(int i = 0;i < 2*n;i+=2){
		sum += v[i];
		sum -= v[i+1];
	}
	cout << sum/2 << endl;
	return 0;
}
