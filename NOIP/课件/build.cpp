#define ll long long//½¨Á¢Ïß¶ÎÊ÷ 
ll a[manx],w[maxn*4];
void pushup(const int u){
	w[u]=a[u*2]+w[u*2+1];
}
void build(const int u,int L,int R){
	if(L==R){
		w[u]=a[L];
		return;
	}
	int M=(L+R)/2;
	build(u*2,L,M),build(u*2+1,M+1,R);
	pushup();
}
