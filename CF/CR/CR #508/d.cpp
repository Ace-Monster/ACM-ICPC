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
//#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 300005;
ll a[maxn],b[maxn];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n,m;
	scanf("%d", &n);
	ll A = 0,B = 0;
	for(int i = 1;i <= n;i++){
		scanf("%lld", &a[i]);
		A += a[i];
	}
	scanf("%d", &m);
	for(int i = 1;i <= m;i++){
		scanf("%lld", &b[i]);
		B += b[i];
	}
	if(A != B){
		printf("-1\n");
		return 0;
	}
	int pa = 1,pb = 1,ans = 0;
	while(pa <= n||pb <= m){
		if(a[pa] == b[pb]){
			ans++,pa++,pb++;
			continue;
		}
		else{
			A = a[pa++],B = b[pb++];
			while(A != B){
				if(A < B){
					A += a[pa++];
					continue;
				}
				if(B < A){
					B += b[pb++];
					continue;
				}
				//dd(A),de(B);
			}
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
