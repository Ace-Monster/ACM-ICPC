struct M {
	int n, m;
	ll a[N][M];//填充矩阵
	M() { }
	M(int t)
	{
		memset(a, 0, sizeof(a));
		n = N,m = M;
		for(int i = 0;i < n;i++)
			a[i][i] = 1;
	}
	const M operator*(const M &x) {
		M b;
		b.n = n, b.m = x.m;
		memset(b.a, 0, sizeof(b.a));
		rep(i, 0, n)
			rep(j, 0, x.m)
			rep(k, 0, m) {
			b.a[i][j] += (a[i][k] * x.a[k][j]) % mod;
			b.a[i][j] %= mod;
		}
		return b;
	}
};
M mulit(M a, ll b) {
	M ant(1);
	while (b) {
		if (b & 1)
			ant = ant * a;
		a = a * a;
		b >>= 1;
	}
	return ant;
}
