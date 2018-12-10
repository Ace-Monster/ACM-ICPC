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
	int a,b,c;
	scanf("%d%d%d", &a, &b, &c);
	int x,y,z;
	scanf("%d%d%d", &x, &y, &z);
	int sum = 0;
	if(x > a)
		sum += x-a;
	if(y > b)
		sum += y-b;
	if(z > c)
		sum += z-c;
	printf("%d\n", sum);
	return 0;
}
