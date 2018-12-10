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
int a[100005];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n;
	cin >> n;
	rep(i, 0, n)
		cin >> a[i];
	rep(i, 1, n - 1)
		a[i] -= a[i-1], a[i+1] -= a[i-1];
	if(a[n - 1] != 0)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}
