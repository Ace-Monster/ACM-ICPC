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
const int maxn = 1000005;
int a[maxn];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	ll n, k;
	scanf("%lld%lld", &n, &k);
	for(int i = 1;i <= n;i++)
		scanf("%d", &a[i]);
	ll tk = sqrt(2*k);
	if(tk*(tk+1) < 2*k) tk++;
	k = k - ((tk-1)*tk/2);
	//dd(k),de(tk);
	printf("%d\n", a[k]);
	return 0;
}
