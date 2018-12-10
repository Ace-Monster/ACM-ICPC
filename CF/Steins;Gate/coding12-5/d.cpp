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

int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int t;
	int ansa = 0,ansb = 0;
	cout << "? " << 0 << " " << 0 << endl;
	cin >> t;
	for(int i = 29;i >= 0;i--){
		cout << "? " << ansa+(1<<i) << " " << ansb+(1<<i) << endl;
		int tt = 0;
		cin >> tt;
		if(tt == t || tt == 0)
			continue;
		if(t == 1)
			ansa+=(1<<i);
		else
			ansb+=(1<<i);
		cout << "? " << ansa << " " << ansb << endl;
		cin >> t;
	}
	for(int i = 29;i >= 0;i--){
		if( (ansa & (1<<i)) || (ansb & (1<<i)) )
			continue;
		cout << "? " << ansa+(1<<i) << " " << ansb << endl;
		cin >> t;
		if(t == -1){
			ansa+=(1<<i);
			ansb+=(1<<i);
		}
	}
	cout << "! " << ansa << " " << ansb << endl;
	return 0;
}
