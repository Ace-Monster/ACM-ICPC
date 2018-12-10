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
const int maxn = 100005;
char b[maxn];
int a[maxn];
bool flag[maxn];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	scanf("%d", &n);
	scanf("%s", b+1);
	for(int i = 1;i <= n;i++)
		scanf("%d", &a[i]);
	int p = 1;
	while(!(p <= 0 || p > n || flag[p])){
		flag[p] = 1;
		//de(p);
		if(b[p] == '>')
			p += a[p];
		else
			p -= a[p];
	}
	if(p <= 0 || p > n)
		puts("FINITE");
	else
		puts("INFINITE");
	return 0;
}
