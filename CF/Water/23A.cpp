#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<functional>
#include<stack>
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
	string s;
	cin >> s;
	int ans = 0;
	int l = s.size();
	for(int i = 0;i < l;i++)
		for(int j = i+1;j < l;j++){
			int k = 0;
			while(s[i+k] == s[j+k] && j+k < l)
				k++;
			ans = max(k, ans);
		}
	cout << ans << endl;
	return 0;
}
