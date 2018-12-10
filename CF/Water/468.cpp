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
map<int, int> q;
const int maxn = 100005;
int num[maxn];
map<int, int> m;
map<int, int> f;
inline int dfs(int x,int t, int a,int b){
	int sum = 0;
	while(m[x] && x > 0){
		sum++;
		f[x] = 1;
		if(t == 0)
			x = a-x;
		else
			x = b-x;
		if(f[x])
			break;
		t = !t;
	}
	return sum;
}
inline void dfss(int s, int x, int t, int a,int b){
	while(m[x] != 0 && m[x] != 1){
		m[x] = s;
		if(t == 0)
			x = a-x;
		else
			x = b-x;
		t = !t;
	}
	return;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n,a,b;
	scanf("%d%d%d", &n, &a, &b);
	for(int i = 1;i <= n;i++){
		scanf("%d", &num[i]);
		m[num[i]] = i+1;
	}
	for(int i = 1;i <= n;i++){
		if(m[num[i]] == 1 || m[num[i]] == 0)
			continue;
		int suma = 0, sumb = 0;
		bool flaga = 0, flagb = 0;
		f[num[i]] = 1;
		if(a - num[i] != num[i])
			suma = dfs(a-num[i], 1, a, b);
		else
			flaga = 1;
		if(b - num[i] != num[i])
			sumb = dfs(b-num[i], 0, a, b);
		else
			flagb = 1;
		if(a == b)
			sumb = 0;
		if((suma+sumb)&1){
			if(!(suma&1)){
				dfss(1, b-num[i], 0, a, b);
				dfss(1, a-num[i], 1, a, b);
				m[num[i]] = 1;
			}
			else{
				dfss(0, b-num[i], 0, a, b);
				dfss(0, a-num[i], 1, a, b);
				m[num[i]] = 0;
			}
		}
		else if(flaga){
			dfss(0, num[i], 1, a, b);
		}
		else if(flagb){
			dfss(1, num[i], 0, a, b);
		}
		else{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for(int i = 1;i <= n;i++){
		printf("%d%c", m[num[i]], i == n ? '\n':' ');
	}
	return 0;
}
