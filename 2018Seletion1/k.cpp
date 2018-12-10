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
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int q;
	cin >> q;
	while(q--){
		double a,b,c;
		cin >> a >> b >> c;
		double eps = 1e-9;
		long double l = log(a)/log(c);
		cout << (long long)(b * l + eps) + 1 << endl;
	}
	return 0;
}
