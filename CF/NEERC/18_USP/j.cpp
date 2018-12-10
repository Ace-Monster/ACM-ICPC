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
int dfs(int i, int l, int n){
	int ti = i;
	if(ti < l)
		return ti;
	if(n < 26)
		ti = dfs(i, l<<1, n+1);
	if(ti == l){
		printf("%c\n", char(n-1+'a'));
		return 0;
	}
	if(ti > l)
		return ti-l;
	return ti;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	scanf("%d", &n);
	dfs(n, 1, 1);
	return 0;
}
