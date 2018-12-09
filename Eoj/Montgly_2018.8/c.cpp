#include<iostream>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>
#include<string.h>
#include<queue>
#include<functional>
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
const int maxn=1e5+10;
int a[maxn], t[maxn];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n,m;
	scanf("%d%d",&n,&m);
	int cnt = 0, maxm = 0;
	a[i] = t[i] = 0;
	for(int i = 2; i <= n+1; i++)
 	   scanf("%d",a[i]),t[i] = a[i];
	int l = n+2;
	a[n+2] = t[n+2] = m;
	sort(t+1,t+l+1);
	N=unique(t+1,t+1+l)-t-1;
	for(int i=1; i <= n; i++)
    	a[i]=lower_bound(t+1,t+1+N,a[i])-t;
	for(int i = 1;i <= l;i++){
		
	}
	return 0;
}
