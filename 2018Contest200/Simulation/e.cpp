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
int mins = 1e9, a[105], maxs = 0;
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n,k;
	cin >> n >> k;
	rep(i, 0, n){
		cin >> a[i];
		mins = min(mins, a[i]);
		maxs = max(maxs, a[i]);
	}
	if(maxs - mins > k)
		return cout << "NO" << endl, 0;
	cout << "YES" << endl;
	rep(i, 0, n){
		int j = 0;
		for(;j < mins;j++)
			cout << 1 <<' ';
		int tt = 1;
		for(;j < a[i];j++)
			cout << tt++ << ' ';
		cout << endl;
	}
	return 0;
}
