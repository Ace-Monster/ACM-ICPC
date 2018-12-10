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
const int maxn = 1000005;
struct A{
	int x, y;
	char w;
}a[maxn];
bool cmpx(A &x, A &y){
	return x.x < y.x;
}
bool cmpy(A &x, A&y){
	return x.y < y.y;
}
bool check(char t){
	if(t == 'b')
		return true;
	return false;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	scanf("%d", &n);
	int sw = 0;
	for(int i = 1;i <= n;i++){
		char s[5];
		scanf("%d%d%s", &a[i].x, &a[i].y, s);
		a[i].w = s[0];
		if(a[i].w == 'w')
			sw++;
	}
	int sum = max(sw, n-sw);
	//de(sum);
	sort(a+1, a+n+1, cmpx);
	int b = 0,w = sw;
	int bi = 0,wi = 0;
	if(check(a[1].w))
		bi++;
	else
		wi++;
	for(int i = 2;i <= n;i++){
		if(a[i].x != a[i-1].x){
			//dd(a[i].x),dd(a[i-1].x),dd(b),dd(w),dd(bi),de(wi);
			sum = max(sum, max(b+bi+w, n-b-w+wi));
			b += bi,w -= wi;
			bi = 0,wi = 0;
		}
		if(check(a[i].w))
			bi++;
		else
			wi++;
	}
	//de(sum);
	sort(a+1, a+n+1, cmpy);
	b = 0,w = sw;
	bi = 0,wi = 0;
	if(check(a[1].w))
		bi++;
	else
		wi++;
	for(int i = 2;i <= n;i++){
		if(a[i].y != a[i-1].y){
			sum = max(sum, max(b+bi+w,n-b-w+wi));
			b += bi,w -= wi;
			bi = 0,wi = 0;
		}
		if(check(a[i].w))
			bi++;
		else
			wi++;
	}
	printf("%d\n", sum);
	return 0;
}
