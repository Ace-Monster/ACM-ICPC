#include<iostream>
#include<vector>
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
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int T;
	cin >> T;
	int i = 1;
	while(T--){
		ll n;
		cin >> n;
		cout << "Case #" << i++ << ": ";
		cout << 8*n*n-7*n+1 << endl;
	}
	return 0;
}
