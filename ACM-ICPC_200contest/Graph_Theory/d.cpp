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
const int maxn = 1001;
int book[maxn+5],x[maxn+5],y[maxn+5];
int find(int xi){
	if(book[xi] == xi)
		return xi;
	return book[xi] = find(book[xi]);
}
void unite(int xi,int yi){
	xi = find(xi), yi = find(yi);
	book[yi] = xi;
	return;
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n,d;
	scanf("%d%d", &n, &d);
	memset(book, -1, sizeof(book));
	for(int i = 1;i <= n;i++){
		scanf("%d%d", &x[i], &y[i]);
	}
	char a;
	getchar();
	while(~scanf("%c", &a)){
		if(a == 'O'){
			int t;
			scanf("%d", &t);
			book[t] = t;
			for(int j = 1;j <= n;j++){
				if(t == j) continue;
				if(book[j] != -1){
					int dx = (x[t]-x[j]),dy = (y[t]-y[j]);
					if(dx*dx+dy*dy <= d*d){
						unite(t,j);
					}
				}
			}
		}
		if(a == 'S'){
			int xi,yi;
			scanf("%d%d", &xi, &yi);
			if(book[xi] == -1 || book[yi] == -1){
				puts("FAIL");
				getchar();
				continue;
			}
			if(find(xi) == find(yi))
				puts("SUCCESS");
			else
				puts("FAIL");
		}
		getchar();
	}
	return 0;
}
