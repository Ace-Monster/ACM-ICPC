int a[maxn];

//nlogn
int getLIS(){
	vi q;
	q.pb(a[1]);
	rep(i, 2, n+1){
		if(a[i] >= q[sz(q)-1]) q.pb(a[i]);
		else{
			auto t = lower_bound(all(q), a[i]);
			*t = a[i];
		}
	}
	return sz(q);
}

//n2
int dp[maxn];
int getLIS(){
	int ans = 0;
	rep(i, 1, n+1){
		dp[i] = 1;
		rep(j, 1, n+1){
			if(a[i] >= a[j])
				dp[i] = max(dp[i], dp[j]+1);
		}
		ans = max(ans, dp[i]);
	}
	return ans;
}

