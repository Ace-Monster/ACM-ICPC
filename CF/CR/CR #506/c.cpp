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
int a[maxn], b[maxn];
bool cmp(int x,int y){
	return y < x;
}
map<pair<int, int>, bool> q;
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d%d", &a[i], &b[i]);
		q[mp(a[i], b[i])] = 1;
	}
	sort(a+1, a+n+1, cmp);
	sort(b+1, b+n+1);
	int ans = max(b[1]-a[2], b[2]-a[1]);
	if(q[mp(a[1], b[1])]) ans = max(ans, b[2]-a[2]);
	if(ans < 0)ans = 0;
	printf("%d\n", ans);
	return 0;
}
