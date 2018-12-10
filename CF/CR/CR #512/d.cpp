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
	ll n,m,k;
	scanf("%lld%lld%lld", &n, &m, &k);
	if(n*m>>1 < k){
		puts("NO");
		return 0;
	}
	int tk = sqrt(k<<1);
	//printf("%d %d\n", 0, 0);
	for(int i = 2;i <= tk;i++){
		if(k%i != 0)
			continue;
		int a = k%i;
		if((i <= n && a <= m) || (i <= m && a <= n)){
			puts("YES");
			printf("%d %d\n", 0, 0);
			printf("%d %d\n", 0, i);
			printf("%d %d\n", a, 0);
			return 0;
		}
	}
	puts("NO");
	return 0;
}
