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
const int maxn = 105;
int m[maxn][maxn];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n,k;
	scanf("%d%d", &n, &k);
	if(k > n*n){
		puts("-1");
		return 0;
	}
	else{
		int i = 0;
		while(k){
			i++;
			if((n-i+1)*2-1 <= k){
				for(int j = i;j <= n;j++)
					m[i][j] = m[j][i] = 1;
				k -= ((n-i+1)*2-1);
			}
			else{
				m[i][i] = 1;
				k--;
				for(int j = i+1;k >= 2;j++){
					m[i][j] = m[j][i] = 1;
					k -= 2;
				}
				if(k) m[i+1][i+1] = 1, k--;
			}
		}
	}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			printf("%d%c", m[i][j], j == n ? '\n' : ' ');
	return 0;
}
