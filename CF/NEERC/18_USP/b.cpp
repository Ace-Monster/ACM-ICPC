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
const int maxn = 2005;
int js[maxn], a[maxn];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
		scanf("%d", &a[i]);
	for(int i = 2;i <= n;i++){
		if(n%i)
			continue;
		int tt = n/i;
		bool flag = 0;
		for(int j = 1;j <= n;j++){
			int t = a[j]%i;
			js[t]++;
			if(js[t] > tt){
				flag = 1;
				break;
			}
		}
		if(flag == 0){
			printf("%d\n", i);
			return 0;
		}
		memset(js, 0, sizeof js);
	}
	printf("%d\n", -1);
	return 0;
}
