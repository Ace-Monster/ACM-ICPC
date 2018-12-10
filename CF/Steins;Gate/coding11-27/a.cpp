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
const int maxn = 105;
char s[maxn];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	if(s[0] == '0'){
		printf("0\n");
		return 0;
	}
	int sum = 0;
	rep(i, 0, n)
		if(s[i] == '0') sum++;
	printf("1");
	rep(i, 0, sum)
		printf("0");
	printf("\n");
	return 0;
}
