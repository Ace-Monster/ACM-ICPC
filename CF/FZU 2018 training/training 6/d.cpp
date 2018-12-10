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
char s[maxn];
vi q;
int n;
bool check(int mid) {
	int sum = 0, t = 1;
	for (auto i : q) {
		if (mid < i)
			return false;
		if (sum + i > mid) {
			sum = i, t++;
		}
		else
			sum += i;
	}
	if (t > n) return false;
	else return true;
}
int main()
{
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	scanf("%d", &n);
	getchar();
	scanf("%[^\n]", &s);
	int ls = strlen(s);
	int p = -1;
	for (int i = 0;i < ls;i++) {
		if (s[i] == ' ' || s[i] == '-') {
			q.pb(i - p);
			p = i;
		}
	}
	q.pb(ls - p - 1);
	int l = 0, r = ls<<1;
	int mid = (l + r) >> 1;
	while (r - l > 1) {
		if (check(mid)) r = mid;
		else l = mid;
		mid = (l + r) >> 1;
	}
	int ans = 0;
	if (check(l)) ans = l;
	else if (check(mid)) ans = mid;
	else ans = r;
	printf("%d\n", ans);
	return 0;
}