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
ll a[1005];
ll tc(int n){
	if(n == 1)
		return a[0];
	if(n == 2)
		return a[1];
	if(n == 3)
		return a[0]+a[1]+a[2];
	ll sum = -a[0];
	for(int i = 1;i < n;i++)
		sum += a[i]+a[0];
	return min(sum, a[0]+a[1]+a[1]+a[n - 1]+tc(n - 2));
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		rep(i, 0, n)
			cin >> a[i];
		sort(a, a+n);
		cout << tc(n) << endl;
	}
	return 0;
}
