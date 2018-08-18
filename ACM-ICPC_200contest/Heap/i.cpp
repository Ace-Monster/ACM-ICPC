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
	int a,b,d;
	bool operator<(const A &x) const{
		return d < x.d;
	}
} c[100005];
struct Cmp{
	bool operator()(const A &a, const A &b){
		return a.a < b.a;
	}
};
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	while(scanf("%d", &n) != EOF){
	priority_queue<A, vector<A>, Cmp> q;
	rep(i, 0, n){
		scanf("%d%d%d", &c[i].a, &c[i].b, &c[i].d);
	}
	sort(c, c+n);
	double x = 0;
	int cnt = 0;
	rep(i, 0, n){
		q.push(c[i]);
		if(c[i].b+cnt > c[i].d){
			int tc = c[i].b+cnt - c[i].d;
			while(tc > 0 && !q.empty()){
				if(q.top().b <= tc){
					x += (double)q.top().b/(double)q.top().a;
					tc -= q.top().b;
					q.pop();
				}
				else{
					x += (double)tc/(double)q.top().a;
					A tt = q.top();
					tt.b -= tc;
					q.pop();
					q.push(tt);
					tc = 0;
				}
			}
			cnt = c[i].d;
		}
		else
			cnt += c[i].b;
	}
	printf("%.2lf\n", x);
	}
	return 0;
}
