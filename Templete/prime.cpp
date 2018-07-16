#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
vi prime;
void Prime(int N){
	int cnt = 0;
	bool tag[N];
	memset(tag, 0, sizeof(tag));
	tag[0] = tag[1] = true;
	for(int i = 2;i < N;i++){
		if(!tag[i])
			prime.push_back(i), cnt++;
		for(int j = 0;j < cnt && prime[j]*i < N;j++){
			tag[i*prime[j]] = 1;
			if(i % prime[j] == 0)//speed up linear time
				break;
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	Prime(100005);
	return 0;
}
