struct BellmanFord

BellmanFord solver;

bool test(double x){
	for(int i=0;i<solver.m;i++){
		solver.edges[i].dist -= x;//ÐÞ¸ÄÈ¨Öµ
	}
	bool ret=solver.negativeCycle();
	for(int i=0;i<solver.m;i++)
	 solver.edges[i].dist += x;
	return ret; 
}

int main(){
	int T;
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++){
		int n,m;
		scanf("%d%d",&n,&m);
		solver.init(n);
		int ub=0;
		while(m--){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			solver.AddEdge(u,v,w);
		}
		printf("Case #%d: ",kase);
		if(!test(ub+1))printf("No cycle found.\n");
		else{
			double L=0,R=ub;
			while(R-L>1e-3){
			  double M=L+(R-L)/2;
			  if(test(M))R=m;
			  else L=m;	
			}
			printf("%.2lf",L);
		}
	}
	return 0;
}
