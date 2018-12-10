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
int a[maxn], b[maxn];
map<int,int> q;
priority_queue<int> bp;
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n,m,d;
	scanf("%d%d%d", &n, &m, &d);
	int ans = 1;
	for(int i = 1;i <= n;i++){
		scanf("%d", &a[i]);
		//bp.push(i);
		q[a[i]] = i;
	}
	sort(a+1, a+n+1);
	b[q[a[1]]] = 1;	
	int sum = 1, p = 1;
	for(int i = 2;i <= n;i++){
		if(a[i] - a[p] > d){
			//bp.push(b[q[a[p]]]);
			b[q[a[i]]] = b[q[a[p]]];
			p++;
			continue;
		}
		b[q[a[i]]] = ++sum;
	}
	printf("%d\n", sum);
	for(int i = 1;i <= n;i++)
		printf("%d ", b[i]);
	return 0;
}
