#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>
#include<string.h>
#include<queue>
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
ll n[105];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int m;
	while(cin >> m){
		if(m == 0) break;
		ll k = 0;
		rep(i, 0, m){
			cin >> n[i];
			k^=n[i];
		}
		ll sum = 0;
		rep(i, 0, m){
			ll t = k^n[i];
			if(t >= 0 && t < n[i])
				sum++;
		}
		cout << sum << endl;
	}
	return 0;
}
