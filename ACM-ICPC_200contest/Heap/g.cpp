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
	int f,s,id;
	A(int a,int b,int c):f(a),s(b),id(c) { }
	bool operator<(const A &x) const{
		return f == x.f ? id < x.id : f > x.f;
	}
};
int main()
{
	int T;
	scanf("%d", &T);
	int t = 0;
	while(T--){
		printf("Case #%d:\n", ++t);
		int n;
		scanf("%d", &n);
		vector<A> q;
		rep(i, 0, n){
			int f,s;
			scanf("%d %d", &f, &s);
			q.pb(A(f, s, i+1));
		}
		vector<A>::iterator it;
		vector<A>::iterator at;
		for(int i = 0;i < 501;i++){
			if(q.size() == 0) break;
			at = q.be();
			for(it = q.be();it != q.en();it++){
				(*it) < (*at) ? at = it : it;
			}
			for(it = q.be();it != q.en();it++)
				it->f += it->s;
			printf("%d%c", (*at).id, q.size()==1 ? '\n':' ');
			q.erase(at);
		}
		sort(q.begin(), q.end());
		int i = 1;
		for(it = q.be();it != q.en();it++){
			printf("%d%c", (*it).id, q.size() == i++ ? '\n':' ');
		}
	}
	return 0;
}
