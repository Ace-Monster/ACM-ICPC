#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define be begin
#define en end
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
struct A{
	int a;
	bool type;
	bool operator<(const A &x) const{
		return a < x.a;
	}
};
vector<A> q;
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int a;
	string t;
	cin >> a >> t;
	int n = t.size();
	for(int i = 0;i < n;i+=6)
	{
		if(t[i+2] == 'a'){
			A tt;
			tt.type = 0;
			tt.a = t[i] - '0';
			q.pb(tt);
		}
		else{
			A tt;
			tt.a = t[i] - '0';
			tt.type = 1;
			q.pb(tt);
		}
	}
	sort(q.be(), q.en());
	vector<A>::iterator it;
	ll sum = 0;
	for(it = q.be(); it != q.en(); it++){
		if(it->type == 0)
		{
			sum += (*it).a*a;
			a++;
		}
		else
		{
			++a;
			sum += (*it).a*a;
		}
	}
	cout << sum << endl;
	return 0;
}

