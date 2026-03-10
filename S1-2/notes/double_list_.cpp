int L[N],R[N],num[N]; // L[i]代表下标为i的左边, R[i]代表下标为i的右边, num[i]代表下标为i的对应值, 后续x,y都代表下标
void link(int x,int y) {R[x] = y, L[y] = x;} // 连接链表中x和y

void insertL(int x,int y) {link(L[x],y); link(y,x);} // 在x的左边插入y
void insertR(int x,int y) {link(y,R[x]); link(x,y);} // 在x的右边插入y
void Delete(int x) {link(L[x],R[x]);} // 删除x结点

int find(int k) { // 寻找第k个元素的下标
	int x = head;
	while (k--) x = R[x];
	return x;
}