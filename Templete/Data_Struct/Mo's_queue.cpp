const int maxn = 500005;
const int inf = 0x3f3f3f3f;
int n, m;
struct Q{
	int l,r,id;
}q[maxn];
int belong[maxn], a[maxn], ans[maxn];
int cnt[maxn<<1];//ͳ����ɫ 
bool cmp(Q x, Q y){//����(l)���򣬿���ͬ�����ż����ŵĿ鰴������(r)���� 
	return ((belong[x.l]^belong[y.l]) ? belong[x.l]<belong[y.l] : ((belong[x.l]&1) ? x.r<y.r : x.r>y.r)); 
}
void init(){//�ֿ� 
	int sn = sqrt(n);//�鳤�� 
	int snum = ceil((double)n/sn);//������ 
	for(int i = 1;i <= snum;i++){//�ֿ� 
		for(int j = (i-1)*sn+1;j <= i*sn; j++)
			belong[j] = i;
	}
}
void work(){//���ߴ��� 
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

