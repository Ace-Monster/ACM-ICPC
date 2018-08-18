#include<iostream>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>
#include<string.h>
#include<queue>
#include<functional>
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
int a[10],dp[10][120005];
bool solve(int sum){
	memset(dp, -1,sizeof dp);
	dp[0][0] = 0;
	for(int i = 1;i <= 6;i++){
		for(int j = 0;j <= sum;j++){
			if(dp[i-1][j] >= 0)
				dp[i][j] = a[i];
			else
				dp[i][j] = -1;
		}
		for(int j = 0;j <= sum - i;j++)
			if(dp[i][j] > 0)
				dp[i][j+i] = max(dp[i][j+i], dp[i][j]-1);
	}
	if(dp[6][sum] == -1)
		return false;
	return true;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int t = 0;
	while(true){
		int sum = 0;
		for(int i = 1;i <= 6;i++){
			scanf("%d", &a[i]);
			sum += a[i]*i;
		}
		if(!sum)
			break;
		if(sum%2){
			printf("Collection #%d:\nCan't be divided.\n", ++t);
			printf("\n");
			continue;
		}
		sum /= 2;
		if(solve(sum))
			printf("Collection #%d:\nCan be divided.\n", ++t);
		else
			printf("Collection #%d:\nCan't be divided.\n", ++t);
		printf("\n");
	}
	return 0;
}
