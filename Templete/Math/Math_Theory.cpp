//欧几里得算法
int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}


//扩展欧几里得算法
//求ax+by=gcd(a,b)的一个特解
//返回gcd(a,b)
int exgcd(int a, int b, int &x, int &y){
	int d = a;
	if(b){
		d = extgcd(b, a%b, y, x);
		y -= (a/b) * x;
	}
	else{
		x = 1,y = 0;
	}
	return d;
}


//求ax=1(mod m)的逆元
int mod_inverse(int a, int m){
	int x,y;
	exgcd(a, m, x, y);
	return (m + x % m) % m;
}


//费马小定理求逆元
int mod_inverse_f(int a, int m){
	a = first_pow(a, m-2);
	return a;
}


//扩展欧几里得求x的最小正整数解
int min_non(int a, int b, int &x, int &y, int c){
	int g = extgcd(a, b, x, y);
	int k = c/g;
	x *= k;
	int db = abs(b/g);
	//int da = abs(a/gcd);=>(x + k*db, y - k*da)
	x = ((x % db) + db) % db;
	y = (n - a*x) / b;
}


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
