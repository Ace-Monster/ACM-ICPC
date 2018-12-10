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
int a[maxn], b[maxn], t[maxn];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	scanf("%d", &n);
	for(int i = 1;i < n;i++)
		scanf("%d", &a[i]);
	for(int i = 1;i < n;i++)
		scanf("%d", &b[i]);
	bool dflag = 0;
	for(int k = 0;k <= 3;k++){
		t[1] = k;
		for(int i = 2;i <= n;i++){
			bool flag = 0;
			for(int j = 0;j <= 3;j++){
				if((t[i-1]|j) == a[i-1] && (t[i-1]&j) == b[i-1]){
					flag = 1;
					t[i] = j;
					break;
				}
			}
			if(!flag)
				break;
			if(i == n)
				dflag = 1;
		}
		if(dflag)
			break;
	}
	if(dflag){
		puts("YES");
		for(int i = 1;i <= n;i++)
			printf("%d%c", t[i], i == n ? '\n':' ');
	}
	else
		puts("NO");
	return 0;
}
