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
const int maxn = 200005;
struct Star{
	int to,next;
}edge[maxn<<1];
int head[maxn], flag[maxn];
int p[maxn];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n, cnt = 0;
	scanf("%d", &n);
	memset(head, -1, sizeof head);
	for(int i = 1;i < n;i++){
		int x,y;
		scanf("%d%d", &x, &y);
		edge[++cnt].to = y;
		edge[cnt].next = head[x];
		head[x] = cnt;
		edge[++cnt].to = x;
		edge[cnt].next = head[y];
		head[y] = cnt;
	}
	for(int i = 1;i <= n;i++){
		scanf("%d", &p[i]);
	}
	queue<int> q;
	if(p[1] != 1){
		puts("No");
		return 0;
	}
	q.push(p[1]);
	cnt = 2;
	while(q.size()){
		int u = q.front();
		q.pop();
		for(int i = head[p[cnt]];i != -1;){
			if(edge[i].to == u){
				q.push(p[cnt++]);
	//			de(p[cnt]);
				i = head[p[cnt]];
			}
			else
				i = edge[i].next;
		}
	}
	if(cnt <= n)
		puts("No");
	else
		puts("Yes");
	return 0;
}
