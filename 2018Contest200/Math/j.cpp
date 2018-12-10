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
ll a[100005], b[100005];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n;
	cin >> n;
	ll sum = 0;
	rep(i, 0, n){
		cin >> a[i];
		sum += a[i];
		b[i] = sum%n;
		if(b[i] == 0){
			cout << i+1 << endl;
			rep(j, 0, i+1)
				cout << a[j] << endl;
			return 0;
		}
	}
	rep(i, 0, n)
		rep(j, i+1, n){
			if(b[i] == b[j]){
				cout << j-i << endl;
				rep(k, i+1, j+1)
					cout << a[k] << endl;
				return 0;
			}
		}
	return 0;
}
