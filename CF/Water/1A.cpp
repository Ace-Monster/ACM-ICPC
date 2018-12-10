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
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	ll n,m,a;
	cin >> n >> m >> a;
	ll na = n/a + (n%a ? 1:0);
	ll nb = m/a + (m%a ? 1:0);
	cout << na*nb << endl;
	return 0;
}
