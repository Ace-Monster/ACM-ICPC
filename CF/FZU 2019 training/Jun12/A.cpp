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
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 105;
const int logn = (log(maxn)/log(2))+1;
const int inf = 0x3f3f3f3f;
const ld eps = 1e-9;
const ll mod = 1e9;
int a[maxn];
vi x[maxn];
bool flag[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n;
	cin >> n;
	int sum = 0;
	rep(i, 1, n+1){
		cin >> a[i];
		sum += a[i];
		x[a[i]].pb(i);
	}
	int k = 2*sum/n;
	rep(i, 1, n+1){
		if(flag[i]) continue;
		cout << i << ' ';
		flag[i] = 1;
		int t = k-a[i];
		for(auto j : x[t]){
			if(!flag[j]){
				cout << j << endl;
				flag[j] = 1;
				break;
			}
		}
	}
	return 0;
}


