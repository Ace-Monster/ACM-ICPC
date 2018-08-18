inline ll solve(ll x, ll y, vi pi) {
	ll n = (1 << pi.size());//取舍总数
	vi::iterator it = pi.be();//集合
	ll sum = 0;//计数
	for (ll m = 1;m < n;m++) {
		ll i = m;
		it = pi.be();
		ll p = 1,t = 0;
		while (i) {
			if (i % 2) {
				p *= (*it);
				t++;
			}
			i >>= 1;
			it++;
		}
		ll xi = ceil((double)x / p), yi = floor((double)y / p);
		if (t % 2)//奇加偶减
			sum += (yi*(yi + 1) / 2 - (xi * (xi - 1)) / 2)*p;
		else
			sum -= (yi*(yi + 1) / 2 - (xi * (xi - 1)) / 2)*p;
	}
	return sum;
}
