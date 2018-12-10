#include<iostream>
#include<stack>
#include<cstdio>
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
const int maxu = 30000, maxv = 150000;
int head[maxu+5];
struct Star{
	int next;
	int to;
	int w;
}edge[maxv+5];
int s[maxu+5];
const int inf = 0x3f3f3f3f;
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n,m;
	scanf("%d%d", &n, &m);
	memset(head, -1, sizeof head);
	for(int i = 0;i < m;i++){
		int a;
		scanf("%d%d%d", &a, &edge[i].to, &edge[i].w);
		edge[i].next = head[a];
		head[a] = i;
	}
	memset(s, inf, sizeof s);
	s[1] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > q;
	q.push(mp(0, 1));
	while(q.size()){
		pii p = q.top();
		q.pop();
		if(p.fi > s[p.se]) continue;
		for(int i = head[p.se];i != -1;i = edge[i].next){
			if(s[edge[i].to] > p.fi + edge[i].w){
				s[edge[i].to] = p.fi + edge[i].w;
				q.push(mp(s[edge[i].to], edge[i].to));
			}
		}
	}
	printf("%d", s[n]);
	return 0;
}
