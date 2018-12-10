const int maxn = 500005;
const int inf = 0x3f3f3f3f;
int n, m;
struct Q{
	int l,r,id;
}q[maxn];
int belong[maxn], a[maxn], ans[maxn];
int cnt[maxn<<1];//统计颜色 
bool cmp(Q x, Q y){//按块(l)排序，块相同的情况偶数编号的块按右区间(r)倒序 
	return ((belong[x.l]^belong[y.l]) ? belong[x.l]<belong[y.l] : ((belong[x.l]&1) ? x.r<y.r : x.r>y.r)); 
}
void init(){//分块 
	int sn = sqrt(n);//块长度 
	int snum = ceil((double)n/sn);//块数量 
	for(int i = 1;i <= snum;i++){//分块 
		for(int j = (i-1)*sn+1;j <= i*sn; j++)
			belong[j] = i;
	}
}
void work(){//离线处理 
	int l = 1, r = 0;
	int tans = 0;
	for(int i = 1;i <= m;i++){
		int ql = q[i].l, qr = q[i].r;
		while(l < ql) tans -= !--cnt[a[l++]];
		while(l > ql) tans += !cnt[a[--l]]++;
		while(r < qr) tans += !cnt[a[++r]]++;
		while(r > qr) tans -= !--cnt[a[r--]];
		ans[q[i].id] = tans;
	}
}
int main()
{
	scanf("%d", &n);
	init();
	for(int i = 1;i <= n;i++) scanf("%d", a+i);
	scanf("%d", &m);
	for(int i = 1;i <= m;i++){ 
		scanf("%d%d", &q[i].l, &q[i].r);
		q[i].id = i;
	}
	sort(q+1, q+m+1, cmp);
	work();
	for(int i = 1;i <= m;i++) printf("%d\n", ans[i]);
	return 0;
}

