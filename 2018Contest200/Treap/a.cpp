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

int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int t;
	scanf("%d", &t);
	set<int> q;
	set<int>::iterator it;
	while(t--){
		char s;
		int k;
		getchar();
		scanf("%c%d",&s,&k);
		if(s == 'I')
			q.insert(k);
		if(s == 'D')
		{
			for(it = q.begin();it != q.end();it++){
				if(*it == k){
					q.erase(it);
					break;
				}
			}
		}
		if(s == 'K'){
			if(k > q.size())
				puts("invalid");
			else{
				it = q.begin();
				for(int i = 1;i < k;i++,it++);
					printf("%d\n", *it);
			}
		}
		if(s == 'C'){
			int sum = 0;
			for(it = q.be();it != q.en();it++)
				if(*it >= k){
					break;
				}
				else
					sum++;
			printf("%d\n", sum);
		}
	}
	return 0;
}
