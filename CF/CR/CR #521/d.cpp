#include<bits/stdc++.h>
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
const int inf = 0x3f3f3f3f;
int a[maxn];
vi q;
map<int, int> p;
vector<pair<int, int> > tq;
int chk(int mid, int k,int l) {
	int t = 0;
	for (int i = 0;i < l;i++) {
		t += (-tq[i].first / mid);
	}
	if (t >= k) return true;
	return false;
}
int main()
{
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	int n,k;
	scanf("%d%d", &n, &k);
	for (int i = 1;i <= n;i++) {
		scanf("%d", &a[i]);
		if (p[a[i]] == 0) q.pb(a[i]);
		p[a[i]]++;
	}
	if(n == k){
		for(int i = 1;i <= n;i++)
			printf("%d%c", a[i], i == n ? '\n':' ');
		return 0;
	}
	for (auto i : q) {
		tq.pb(mp(-p[i], i));
	}
	sort(tq.begin(), tq.end());
	int l = 0, r = n;
	int mid = (l + r) >> 1;
	int tl = tq.size();
	while (r - l > 1) {
		if (chk(mid, k, tl)) l = mid;
		else r = mid;
		mid = (l + r) >> 1;
	}
	int tans = 0;
	if (chk(l, k, tl)) tans = l;
	else if (chk(mid, k, tl)) tans = mid;
	else if (chk(r, k, tl)) tans = r;
	q.clear();
	for (int i = 0;i < tl;i++) {
		int t = (-tq[i].first / tans);
		if (t > k) {
			for (int j = 1;j <= k;j++)
				q.pb(tq[i].second);
			k = 0;
		}
		else {
			for (int j = 1;j <= t;j++)
				q.pb(tq[i].second);
			k -= t;
		}
	}
	k = q.size();
	int tt = 0;
	for (auto i : q) {
		printf("%d%c", i, ++tt == k ? '\n' : ' ');
	}
	return 0;
}
