

struct HeapNode{
	int d,u;
	bool operator < (const HeapNode& rhs) const {
	  return d>rhd.d
	}
};
struct dijkstra{
	int n,m;          //点数和边数 
	vector<Edge>edges;//边列表 
	vector<int>G[maxn];//每个结点出发的边编号(从0开始编号) 
	bool done[maxn];//是否已永久标号
	int d[maxn];//s到各个点的距离 
	int p[maxn];//最短路中的上一条边
	
	void init(int n){
		this->n = n;
		for(int i=0;i<n;i++)G[i].clear();
		edges.clear();
	} 


void AddEdge(int from,int to,int dist){
	edges.push_back((Edge){from,to,dist});
	m=edges.size();
	G[from].push_back(m-1); 
}

void dijkstra(int s){
	priority_queue<HespNode>Q;
	for(int i=0;i<n;i++)d[i]=INF;
	d[s]=0;
	memset(done,0,sizeof(done));
	Q.push(HapsNode){0,s});
	while(!Q.empty()){
		HapsNode x=Q.top();Q.pop();
		int u=x.u;
		if(done[u])continue;
		done[u]=true;
		for(int i=0;i<G[u].size();i++){
			Edge& e=edge[G[u][i]];
			if(d[e.to]>d[u]+e.dist){
				d[e.to]=d[u]+e.dist;
				p[e.to]=G[u][i];
				Q.push((HeapNode){d[e.to],e.to})
			}
		}
	}
}
};
