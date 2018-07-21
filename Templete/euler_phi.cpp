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
