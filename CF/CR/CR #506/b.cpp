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
	int n;
	scanf("%d", &n);
	ll a = 0,b = 0;
	int sum = 1,ans = 0;
	for(int i = 1;i <= n;i++){
		scanf("%lld", &b);
		if(b <= a*2)
			sum++;
		else{
			ans = max(ans, sum), sum = 1;
		}
		a = b;
	}
	ans = max(ans, sum);
	printf("%d", ans);
	return 0;
}
