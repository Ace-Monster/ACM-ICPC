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
const int maxn = 50000;
struct TREE{
	int father;
	int relation;//0->同类，1->被吃，2->吃
}tree[maxn+5];
int find(int rt){
	if(rt == tree[rt].father) return rt;
	int trt = find(tree[rt].father);
	tree[rt].relation = (tree[rt].relation+tree[tree[rt].father].relation)%3;
	tree[rt].father = trt;
	return trt;
}
void unite(int re,int x,int y,int dx,int dy){
	tree[dy].father = dx;
	tree[dy].relation = (tree[x].relation + re +(3-tree[y].relation))%3;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n,k;
	scanf("%d%d", &n, &k);
		for(int i = 1;i <= n;i++){
			tree[i].father = i, tree[i].relation = 0;
		}
		int sum = 0;
		while(k--){
			int d,x,y;
			scanf("%d%d%d", &d, &x, &y);
			if(x > n || y > n){
				sum++;
				continue;
			}
			if(d == 1){
				int dx = find(x),dy = find(y);
				if(dx != dy)
					unite(d - 1,x,y,dx,dy);
				else if(tree[x].relation != tree[y].relation)
					sum++;
			}
			if(d == 2){
				if(x == y){
					sum++;
					continue;
				}
				int dx = find(x),dy = find(y);
				if(dx != dy)
					unite(d - 1,x,y,dx,dy);
				else if(((3-tree[x].relation + tree[y].relation)%3) != 1)
					sum++;
			}
		}
		printf("%d\n", sum);
	return 0;
}
