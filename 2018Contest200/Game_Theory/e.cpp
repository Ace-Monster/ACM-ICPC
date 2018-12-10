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
//当k>1时，只要n > k先手必败
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	ll n,k;
	int T;
	cin >> T;
	int t = 0;
	while(T--){
		cout << "Case " << ++t << ": ";
		cin >> n >> k;
		if(k == 1){
			if(n%2) cout << "first" << endl;
			else cout << "second" << endl;
			continue;
		}
		if(n <= k) cout << "first" << endl;
		else cout << "second" << endl;
	}
	return 0;
}
