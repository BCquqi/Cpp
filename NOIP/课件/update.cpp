void update1(int u,int L,int R,int p,LL x){
		if(L==R)
	      w[u]=x;
	else{
		int M=(L+R)/2;
		if(M>p)
		  update1(u*2,L,M,p,x);
		else
		  update1(u*2+1,M+1,R,p,x);  
	} 
	pushup();
}
