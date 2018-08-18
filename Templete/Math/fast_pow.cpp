ll mod;
inline ll mods(ll a,ll b){
	if(a+b >= mod)
		return a+b - mod;
	return a+b;
}

inline ll first_mulit(ll a,ll b){//快速乘
	ll sum = 0;
	while(b){
		if(b&1)
			sum = mods(sum, a);
		a = mods(a, a);
		b>>=1;
	}
	return sum%mod;
}

inline ll first_pow(ll a,ll b){//快速幂
	a%=mod;//初始可能a>c
	ll sum = 1;
	while(b){
		if(b&1)
			sum = first_mulit(sum, a);
		a = first_mulit(a, a);
		b>>=1;
	}
	return sum%mod;
}

