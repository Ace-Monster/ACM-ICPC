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
const int maxq = 100005;
int a[maxn][maxn];
struct Q{
	int op;
	int x,y,z;
}q[maxq];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n,m,t;
	scanf("%d%d%d", &n, &m, &t);
	for(int i = 1;i <= t;i++){
		scanf("%d", &q[i].op);
		int op = q[i].op;
		if(op == 1){
			scanf("%d", &q[i].x);	
		}
		if(op == 2){
			scanf("%d", &q[i].x);
		}
		if(op == 3){
			scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].z);
		}
	}
	for(int i = t;i >= 1;i--)
	{
		int op = q[i].op;
		if(q[i].op == 1)
		{
			int x = q[i].x;
			swap(a[x][1], a[x][m]);
			for(int j = m-1;j >= 2;j--){
				swap(a[x][j], a[x][j+1]);
			}
		}
		if(q[i].op == 2){
			int x = q[i].x;
			swap(a[1][x], a[n][x]);
			for(int j = n-1;j >= 2;j--){
				swap(a[j][x], a[j+1][x]);
			}
		}
		if(q[i].op == 3){
			a[q[i].x][q[i].y] = q[i].z;
		}
	}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			printf("%d%c", a[i][j], j == m ? '\n':' ');
	return 0;
}
