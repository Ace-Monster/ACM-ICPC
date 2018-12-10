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
int a[200005];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n;
	while(cin >> n){
		if(n == 0) break;
		int k = 0;
		rep(i, 0, n){
			cin >> a[i];
			k ^= a[i];
		}
		if(k == 0){
			cout << "No" << endl;
			continue;
		}
		cout << "Yes" << endl;
		rep(i, 0, n){
			int t = a[i]^k;
			if(t < 0 || t >= a[i])
				continue;
			cout << a[i] << ' ' << t << endl;
		}
	}
	return 0;
}
