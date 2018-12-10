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
const int maxn = 100005;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9;
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int a,b,c;
	cin >> a >> b >> c;
	if(a == b) {
		cout << "YES";
		return 0;
	}
	if(c == 0){
		cout << "NO";
		return 0; 
	} 
	if(c > 0 && b < a){
		cout << "NO";
		return 0;
	}
	if(c < 0 && b > a){
		cout << "NO";
		return 0;
	}
	if((b-a)%c == 0)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}


