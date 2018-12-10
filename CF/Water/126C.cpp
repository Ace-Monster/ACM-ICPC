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
const int maxn = 2000005;
int f[maxn];
char s[maxn];
void fnext(int n){
	f[0] = -1;
	for(int i = 1;i < n;i++){
		int j = f[i-1];
		while(s[j+1] != s[i] && j >= 0)
			j = f[j];
		if(s[j+1] == s[i])
			f[i] = j+1;
		else
			f[i] = -1;
	}
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	scanf("%s", s);
	int n = strlen(s);
	fnext(n);
	int i = n-1;
	map<int, bool> q;
	if(f[i] != -1){
		while(f[i] != -1){
			q[f[i]] = 1;
			i = f[i];
		}
		int ans = -1;
		for(i = 1;i < n-1;i++){
			if(q[f[i]])
				ans = max(ans, f[i]);
			//dd(f[i]),dd(q[f[i]]),de(ans);
		}
		if(ans == -1)
			puts("Just a legend");
		else
			for(int i = 0;i <= ans;i++)
				printf("%c", s[i]);
	}
	else
		puts("Just a legend");
	return 0;
}
