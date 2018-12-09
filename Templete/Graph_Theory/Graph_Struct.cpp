//前向星
struct Star{
	int to,next;
}edge[maxv];
int head[maxn], cnt;
void init(){
	memset(head, 0, sizeof head);
	cnt = 0;
}
void add_edge(int x,int y){//x->y
	edge[++cnt].to = y;
	edge[cnt].next = head[x];
	head[x] = cnt;
}


//邻接矩阵
vector<int> edge[maxn];
void add_edge(int x,int y){
	edge[x].push_back(y);
}
void find(int u){
	vector<int>::iterator it;
	for(it = edge[u].begin();it != edge[u].end();it++){
		find(*it);
	}
}

//领接表
int edge[maxn][maxn];
