typedef vector<int> vi;
const int maxn = 100005;
vi edge[maxn];
int f[maxn],d[maxn];//���ױ��,��� 
int size[maxn], son[maxn], rk[maxn], top[maxn], id[maxn];
//size[u]:uΪ�����ӽڵ����
//son[u]:u���ض���
//rk[u]:���u(dfs��)��ԭͼ�еı��
//top[u]:u�ڵ������������
//id[u]:u�ڵ���dfs���еı��

void dfs1(int u, int fa, int dep){//��һ��dfs
	f[u] = fa;
	d[u] = dep++;
	size[u] = 1;
	for(auto i : edge[u]){
		if(i == fa) continue;
		dfs1(i,u,dep);
		size[u] += size[i];
		if(size[i] > size[son[u]])
			son[u] = i;
	}
}

int cnt;//�ڶ���dfs 
void dfs2(int u, int t){
	top[u] = t;
	id[u] = ++cnt;
	rk[cnt] = u;
	//sum[cnt] = sum[cnt-1]+a[u]-a[f[u]]; //�����
	if(!son[u]) return;
	dfs2(son[u], t);
	for(auto i:edge[u]){
		if(i != son[u] && i != f[u])
			dfs2(i, i);
	}
} 

//�߶���ά������ 
void UPD(int x, int y){
	while(top[x] != top[y]){
		if(d[top[x]] < d[top[y]]) swap(x, y);
		update(id[top[x]], id[x], 1, n, 1);//�߶������� 
		x = f[top[x]];
	}
	if(d[x] < d[y]) swap(x, y);
	update(id[y], id[x], 1, n, 1);//�߶������� 
}

//�߶�����ѯ��������ѯĳ�����ĺͣ� 
ll QUE(int x, int y){
	ll res = 0;
	while(top[x] != top[y]){
		if(d[top[x]] < d[top[y]]) swap(x, y);
		res += query(id[top[x]], id[x], 1, n, 1);//�߶�����ѯ 
		x = f[top[x]];
	}
	if(d[x] < d[y]) swap(x, y);
	res += query(id[y], id[x], 1, n, 1);//�߶�����ѯ 
	return res;
}


