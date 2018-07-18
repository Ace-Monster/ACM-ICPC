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
int n,a,b,c;
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	cin >> a >> b >> c >> n;
	int t = n-(a+b-c);
	if(!(t >= 1&&t <= n) || c > min(a, b))
		return cout << -1 << endl, 0;
	cout << n -a-b+c << endl;
	return 0;
}
