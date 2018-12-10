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
const int maxn = 300005;
struct A{
	int id,a,b,k;
	bool operator<(const A &x) const{
		if(a != x.a) return a<x.a;
		//if(b != x.b) return b<x.b;
		if(k*x.k != 1){
			return k == 1;
		}
		if(b != x.b) return b > x.b;
		if(k == 1)
			return id < x.id;
		return id > x.id;
	}
}s[maxn<<1];
void add(int cnt, int id, int k,int a,int b){
	s[cnt].id = id;
	s[cnt].k = k;
	s[cnt].a = a;
	s[cnt].b = b;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
    int n;
    scanf("%d", &n);
    int cnt = 0;
    rep(i, 0, n){
		int a, b;
		scanf("%d %d", &a, &b);
		add(cnt++, i+1, 1, a, b);
		add(cnt++, i+1, -1, b, a);
	}
	sort(s, s+cnt);
	queue<int> q;
	rep(i, 0, cnt){
		//dd(s[i].id), de(s[i].k);
		if(s[i].k == 1) q.push(i);
		else{
			if(s[q.front()].id == s[i].id)
				q.pop();
			else{
				printf("%d %d\n", s[i].id, s[q.front()].id);
				return 0;
			}
		}
	}
	puts("-1 -1");
	return 0;
}
