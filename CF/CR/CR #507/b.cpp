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
const int maxn = 200005;
ll a[maxn];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n,s;
	scanf("%d%d", &n, &s);
	for(int i = 1;i <= n;i++){
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+n+1);
	int l = lower_bound(a+1, a+n+1, s)-a;
	if(l > n) l = n;
	int t = n>>1;
	t++;
	ll sum = 0;
	if(l > t){
		while(a[l] > s)l--;
		for(int i = l;i >= t;i--)
			sum += abs(s-a[i]);
	}
	else{
		for(int i = l;i <= t;i++)
			sum += abs(a[i]-s);
	}
	printf("%lld\n", sum);
	return 0;
}
