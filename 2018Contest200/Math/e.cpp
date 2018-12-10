#include<iostream>
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
int BtA[1005], BtC[1005];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int a,b,c;
	while(cin >> a >> b >> c){
		if(a == 0)break;
		int n;
		ll sum = 0;
		cin >> n;
		rep(i, 0, b)
			BtA[i] = a, BtC[i] = c;
		rep(i, 0, n){
			string s, t;
			int j, k;
			cin >> s >> j >> t >> k;
			if(s[0] == 'c'){
				BtA[k - 1]--;
			}
			else{
				BtC[j - 1]--;
			}
		}
		rep(i, 0, b)
			sum += BtA[i]*BtC[i];
		cout << sum << endl;
	}
	return 0;
}
