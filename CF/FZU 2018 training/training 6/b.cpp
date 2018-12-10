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
int a[maxn];
int q[maxn],p[maxn];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	scanf("%d", &n);
	int t = -1;
	for(int i = 1;i <= n;i++){
		scanf("%d", &a[i]);
		if(a[i] == 0)
			t = i;
		else if(t != -1)
			q[i] = i-t;
		else
			q[i] = maxn;
	}
	t = -1;
	for(int i = n;i >= 1;i--){
		if(a[i] == 0)
			t = i;
		else if(t != -1)
			p[i] = t-i;
		else
			p[i] = maxn;
	}
	for(int i = 1;i <= n;i++){
		printf("%d%c", min(q[i], p[i]), i == n ? '\n':' ');
	}
	return 0;
}
