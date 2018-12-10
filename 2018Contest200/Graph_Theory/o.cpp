#include<cstdio>
#include<iostream>
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
const int maxn = 500;
struct Star{
	int next, to;
}edge[10000];
int head[10000];
char maps[maxn+5][maxn+5];
int mapx[maxn+5][maxn+5],mapy[maxn+5][maxn+5];
bool flag[10000];
int match[10000];
bool find(int u){
	for(int i = head[u];i != -1;i = edge[i].next){
		int to = edge[i].to;
		if(!flag[to]){
			flag[to] = true;
			if(match[to] == 0 || find(match[to])){
				match[to] = u;
				return true;
			}
		}
	}
	return false;
}
int hungary(int n){
	int sum = 0;
	for(int i = 1;i <= n;i++){
		if(find(i))
			sum++;
		memset(flag, 0 ,sizeof flag);
	}
	return sum;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int r,c;
	scanf("%d%d", &r, &c);
	for(int i = 0;i < r;i++)
		scanf("%s", maps[i]);
	int cnt = 0;
	bool f = false;
	int n = 0;
	for(int i = 0;i < r;i++){
		for(int j = 0;j < c;j++){
			if(f && maps[i][j] == '.')f = false;
			if(maps[i][j] == '*'){
				if(f == false)++cnt;
				f = true;
				mapx[i][j] = cnt;
				n = cnt;		
			}
		}
		f = false;
	}
	cnt = 1;
	for(int j = 0;j < c;j++){
		for(int i = 0;i < r;i++){
			if(f && maps[i][j] == '.') f = false;
			if(maps[i][j] == '*'){
				if(f == false)++cnt;
				f = true;
				mapy[i][j] = cnt;
			}
		}
		f = false;
	}
	cnt = 1;
	memset(head, -1, sizeof head);
	for(int i = 0;i < r;i++)
		for(int j = 0;j < c;j++){
			if(maps[i][j] == '*'){
				edge[cnt].to = mapy[i][j];
				edge[cnt].next  = head[mapx[i][j]];
				head[mapx[i][j]] = cnt++;
			}
		}
	printf("%d\n", hungary(n));
	return 0;
}
