#include<iostream>
#include<vector>
#include<cstdio>
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
int f[100005];
bool d[100005];
int v[100005];
int find(int x){
	if(f[x] == x)
		return x;
	f[x] = find(f[x]);
	return f[x];
}
void unite(int x,int y){
	x = find(x);
	y = find(y);
	if(y == x) return;
	f[x] = y;
	return;
}
int main()
{
	int x,y;
	int t = 0;
	while(cin >> x >> y){
		if(x == -1)break;
		cout << "Case " << ++t;
		for(int i = 1;i <= 100000;i++)
			f[i] = i;
		bool flag = false;
		memset(d, 0, sizeof(d));
		memset(v, 0, sizeof(v));
		int ma = 0,mi = 0x3f3f3f3f;
		while(true){
			if(x == 0)break;
			ma = max(ma,max(x,y));
			mi = min(mi,min(x,y));
			v[y]++;
			if(v[y] > 1)
				flag = true;//树入度小于1
			if(!flag){
				if(find(x) == find(y)){
					flag = true;
				}
				else{
					unite(x,y);
				}
			}
			d[x] = 1,d[y] = 1;
			cin >> x >> y;
		}
		if(!flag && ma != 0){
			int ff = find(mi);
			for(int i = mi+1;i <= ma;i++){
				if(d[i] == 0) continue;
				if(ff != find(i)){
					flag = true;
					break;
				}
			}
		}
		if(!flag)
			cout << " is a tree." << endl;
		else
			cout << " is not a tree." << endl;
	}
	return 0;
}
