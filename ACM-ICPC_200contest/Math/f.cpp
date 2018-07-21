#include<iostream>
#include<cmath>
#include<vector>
#include<string>
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

int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int T;
	cin >> T;
	int j = 1;
	while(T--){
		cout << "Case " << j++ << ':' << endl;
		long double ua,u0,u1,t1,n;
		cin >> ua >> u0 >> u1 >> t1 >> n;
		long double k,c;
		if(u0 == ua)
			k == 1, c == 0;
		else{
			c = log(u0 - ua);
			k = (log(u1 - ua)-c)/t1;
		}
		rep(i, 0, n){
			int p;
			long double s;
			cin >> p >> s;
			switch(p){
				case 0:
					if(u0 == ua) printf("%.2f\n", 0.0);
					else printf("%.2Lf\n", (log(s-ua)-c)/k);
					//cout << (log(s-ua)-c)/k << endl;
					break;
				case 1:
					if(u0 == ua) printf("%.2Lf\n", ua);
					else printf("%.2Lf\n", exp(k*s+c)+ua);
					//cout << exp(k*s+c)+ua << endl;
			}
		}
		cout << endl;
	}
	return 0;
}
