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
int d[100005];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n, s;
	cin >> n >> s;
	ll sum = 0;
	cin >> d[0] >> sum;
	sum *= d[0];
	rep(i, 1, n){
		int temp;
		cin >> d[i] >> temp;
		d[i] = min(d[i], d[i-1]+s);
		sum += d[i]*temp;
	}
	cout << sum << endl;
	return 0;
}
