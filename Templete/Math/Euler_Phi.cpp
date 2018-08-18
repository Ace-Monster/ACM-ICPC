//欧拉函数筛
const int MAXN = 400005;
int phi[MAXN];
void euler_phi2(){
	for(int i = 0;i < MAXN;i++)
		phi[i] = i;
	for(int i = 2;i < MAXN;i++)
		if(phi[i] = i)
			for(int j = i;j < MAXN;j++)  phi[j] = phi[j]/i*(i-1);
}


//欧拉函数
ll phi(ll n){
	ll res = n;
	for(ll i = 2;i < n;i++){
		if(n % i == 0){
			res = res / i * (i - 1);
			while(n % i == 0) n /= i;
		}
	}
	if(n != 1) res = res / n * (n-1);
	return res;
}


//欧拉降幂
//n^x % m = n^(phi(m) + x % phi(m)) % m;
