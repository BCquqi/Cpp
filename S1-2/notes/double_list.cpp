void link(int x,int y) {R[x] = y, L[y] = x;}

void insertL(int x,int y) {link(L[x],y); link(y,x);}
void insertR(int x,int y) {link(y,R[x]); link(x,y);}
void Delete(int x) {link(L[x],R[x]);}

int find(int k) {
	int x = head;
	while (k--) x = R[x];
	return x;
}