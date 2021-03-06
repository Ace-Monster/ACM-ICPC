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
	string s;
	while(cin >> s){
		if(s[0] == '0')
			break;
		ll l = s.size();
		ll sum = 0;
		for(int i = 0;i < l;i++)
			sum += s[i] - '0';
		sum%=9;
		if(sum == 0)
			cout << 9 << endl;
		else
			cout << sum << endl;
	}
	return 0;
}
