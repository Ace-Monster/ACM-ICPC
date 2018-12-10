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
map<int, int> xi;
map<int, int> yi;
int maps[1005][1005];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	rep(i, 1, n+1)
		xi[i] = i;
	rep(i, 1, m+1)
		yi[i] = i;
	rep(i, 1, n+1)
		rep(j, 1, m+1)
			cin >> maps[i][j];
	while(q--){
		int t, a, b;
		cin >> t >> a >> b;
		if(t == 0)
			swap(xi[a], xi[b]);
		if(t == 1)
			swap(yi[a], yi[b]);
		if(t == 2)
			cout << maps[xi[a]][yi[b]] << endl;
	}
	return 0;
}
