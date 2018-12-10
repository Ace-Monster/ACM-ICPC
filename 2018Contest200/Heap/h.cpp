#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>
#include<string.h>
#include<queue>
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
struct A{
	int p,s;
	bool operator<(const A &x) const{
		return p > x.p;
	}
}a[10005];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n;
	while(cin >> n){
		rep(i, 0, n)
			cin >> a[i].p >> a[i].s;
		int l,p;
		sort(a, a+n);
		priority_queue<int> q;
		cin >> l >> p;
		int sum = 0;
		a[n].p = 0;
		rep(i, 0, n+1){
			while(l-a[i].p > p && !q.empty()){
				p += q.top();
				q.pop();
				sum++;
			}
			if(l-a[i].p > p){
				sum = -1;
				break;
			}
			q.push(a[i].s);
		}
		cout << sum << endl;
	}
	return 0;
}
