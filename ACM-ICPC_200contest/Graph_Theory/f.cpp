#include<iostream>
#include<cstdio>
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
const int maxv = 1000;
struct EDGE{
	double r,l;
}edge[maxv+5][maxv+5];
double d[maxv+5];
bool inq[maxv+5];
int ins[maxv+5];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	memset(edge, -1, sizeof edge);
	int n,m,s;
	double v;
	scanf("%d%d%d%lf", &n, &m, &s, &v);
	for(int i = 0;i < m;i++){
		int a,b;
		scanf("%d%d", &a, &b);
		scanf("%lf%lf%lf%lf", &edge[a][b].r,&edge[a][b].l,&edge[b][a].r,&edge[b][a].l);
	}
	queue<int> q;
	memset(d, 0, sizeof d);
	d[s] = v;
	q.push(s);
	while(q.size()){
		int p = q.front();
		inq[p] = 0;
		q.pop();
		for(int i = 1;i <= n;i++){
			if(edge[p][i].l == -1) continue;
			if(d[i] < (d[p]-edge[p][i].l)*edge[p][i].r){
				d[i] = (d[p]-edge[p][i].l)*edge[p][i].r;
				if(inq[i] == 1) continue;
				q.push(i);
				inq[i] = 1;
			}
		}
		if(ins[p]++ > 2*n){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}
