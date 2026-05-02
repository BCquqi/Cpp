#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<map>
#include<queue>
#include<vector>
#include<set>
#include<cmath>
#include<sstream>
using namespace std;
#define ll long long

const int mx = 1111;

struct edge{
	int u, v, w;
}a[mx * mx], nw[mx*3];
int edge_size; // a为原边， nw为筛出来的边。原边个数需要记录，新边当然是n-1条。 



int T, n, m;
string line; 
int x[mx], y[mx];//题目条件 

int st[11][mx], size[11], mon[11];//套餐 

int fat[mx];//并查集 
inline int find(int x) { return fat[x] == x ? x : fat[x] = find(fat[x]); }
inline void reset() { for(int i = 1; i <= n; i++)fat[i] = i; }

//建图 
inline int diss(int i, int j) { return  (x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]); }
inline void addedge(int k){
	for(int i = 1; i < k; i++) {
		edge_size++;
		a[edge_size].u = i; a[edge_size].v = k; a[edge_size].w = diss(i, k);
	}
}

inline int cmp(edge x, edge y){
	return x.w < y.w;
}

//返回花费，tot为已经有了多少边,cnt为要处理的边集合的数量，op为处理旧图还是新图,cost为已经花了多少钱。 
inline int Kruskal(int tot, int cnt, int op, int cost){
	int sum = cost;
	if(op){
		for(int i = 1; i <= cnt; i++){
		int fu = find(a[i].u), fv = find(a[i].v);
		if(fu != fv){
			fat[fu] = fv;
			tot++;
			sum += a[i].w;
			if(op)nw[tot] = a[i];
			if(tot == n-1)break;
		}
	}
	}
	else{
		for(int i = 1; i <= cnt; i++){
		int fu = find(nw[i].u), fv = find(nw[i].v);
		if(fu != fv){
			fat[fu] = fv;
			tot++;
			sum += nw[i].w;
			if(tot == n-1)break;
		}
	}
	}
	return sum;
	
}

inline int solve(int cost){
	
	int ans = cost;
    
	for(int S = 0; S < (1<<m); S++){
		
		reset();
		
		int tot = 0;
		int need = 0;
		for(int q = 1; q <= m; q++){
			if(S & (1<<(q-1))){
			
			need += mon[q];
			for(int i = 1; i < size[q]; i++){
				for(int j = i+1; j <= size[q]; j++){
					
					int u = find(st[q][i]), v = find(st[q][j]);
					if(u != v){
						fat[u] = v;
						tot++;
					}
				}
			}
		}
		}
		ans = min(ans, Kruskal(tot, n-1, 0, need));
	}
	return ans;
}
int main(){
    cin >> T;
    while(T--){
    	edge_size = 0;
   // 	memset(size, 0, sizeof(size));
    //	memset(fat, 0, sizeof(fat));
    	
    	
    	getline(cin, line);//有没有都行
    	
    	scanf("%d %d", &n, &m);
    	
    	for(int i = 1; i <= m; i++){
    		scanf("%d %d", &size[i], &mon[i]);
    		for(int j = 1; j <= size[i]; j++)scanf("%d", &st[i][j]);
		}
    	for(int i = 1; i <= n; i++){
    		scanf("%d%d", &x[i], &y[i]);
    		addedge(i);
		}
		sort(a + 1, a + edge_size + 1, cmp);
		reset();
		int  cost = Kruskal(0, edge_size, 1, 0);
		printf("%d\n", solve(cost));
		if(T)putchar('\n');
	}
	return 0;
}