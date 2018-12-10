#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<functional>
#include<stack>
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
	freopen("katryoshka.in", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int i = 1;i <= T;i++){
		int n,m,k;
		scanf("%d%d%d", &n, &m, &k);
		int ans = 0;
		if(k <= m)
			ans = min(n, k);
		else{
			if(n <= m)
				ans = n;
			else{
				ans = m;
				k -= m,n -= m;
				ans += min(k, n/2);
			}
		}
		printf("Case %d: %d\n", i, ans);
			
	}
	return 0;
}
