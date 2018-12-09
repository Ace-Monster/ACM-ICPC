#define _CRT_SECURE_NO_DEPRECATE
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
const int maxn = 200000;
const double eps = 1e-9;
int a[maxn + 5][32], b[maxn + 5][32];
void makest(int n) {
	for (int j = 1;(1 << j) <= n;j++)
		for (int i = 1;i + (1 << j) - 1 <= n;i++)
			a[i][j] = max(a[i][j - 1], a[i + (1 << (j-1))][j - 1]),
			b[i][j] = min(b[i][j - 1], b[i + (1 << (j-1))][j - 1]);
}
bool query_big(int l, int r) {
	int k = log2(r - l + 1.0) + eps;
	return max(a[l][k], a[r - (1 << k) + 1][k]) > min(b[l][k], b[r - (1 << k) + 1][k]);
}
bool query_sma(int l, int r) {
	int k = log2(r - l + 1.0) + eps;
	return max(a[l][k], a[r - (1 << k) + 1][k]) < min(b[l][k], b[r - (1 << k) + 1][k]);
}
bool query_quer(int l, int r) {
	if (l == 4) 
		int aaa = 1;
	int k = log2(r - l + 1.0) + eps;
	return max(a[l][k], a[r - (1 << k) + 1][k]) == min(b[l][k], b[r - (1 << k) + 1][k]);
}
int main()
{
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	int n;
	scanf("%d", &n);
	for (int i = 1;i <= n;i++)
		scanf("%d", &a[i][0]);
	for (int i = 1;i <= n;i++)
		scanf("%d", &b[i][0]);
	makest(n);
	ll sum = 0;
	for (int i = 1;i <= n;i++) {
		int l1 = i - 1, r1 = n+1;
		int mid;
		while (r1 - l1 > 1) {
			mid = (r1 + l1) / 2;
			if (query_big(i, mid) || query_quer(i, mid)) r1 = mid;
			else l1 = mid;
		}
		r1;
		int l2 = i - 1,r2 = n+1;
		while (r2 - l2 > 1) {
			mid = (r2 + l2) / 2;
			if (query_sma(i, mid) || query_quer(i, mid)) l2 = mid;
			else r2 = mid;
		}
		sum += (l2 - r1 + 1);	
	}
	printf("%lld\n", sum);
	return 0;
}
