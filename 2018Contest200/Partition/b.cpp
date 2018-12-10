#include<iostream>
#include<stack>
#include<vector>
#include<map>
#include<cstdio>
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
int cnu;
char a[30],b[30];
void dfs(int l,int r){
	int root = a[cnu++];
	if(l == r){
		printf("%c", root);
		return;
	}
	for(int i = l;i <= r;i++){
		if(b[i] == root){
			if(i-1 >= l)
				dfs(l,i-1);
			if(i+1 <= r)
				dfs(i+1,r);
			break;
		}
	}
	printf("%c", root);
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	while(~scanf("%s %s", a, b)){
		int l = 0, r = strlen(a)-1;
		cnu = 0;
		dfs(l,r);
		printf("\n");
	}
	
	return 0;
}
