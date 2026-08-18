#include<iostream>
#include<ctime>
#include<cstdlib>
#include<random>
using namespace std;

const int N = 1;
mt19937 gen(time(0));
struct Node {int ls,rs,sz,fix,val;} tr[N];
int idx = 0,rt;

int create(int id) {tr[++idx] = {0,0,1,(int)gen(),id}; return idx;}

void pushup(int id) {tr[id].sz = tr[tr[id].ls].sz + tr[tr[id].rs].sz + 1;}

int merge(int x,int y) {
    if (!x || !y) return x + y;
    if (tr[x].fix > tr[y].fix) {
        tr[x].rs = merge(tr[x].rs,y);
        pushup(x);
        return x;
    } else {
        tr[y].ls = merge(x,tr[y].ls);
        pushup(y);
        return y;
    }
}

void split(int id,int k,int &x,int &y) { // <= k 进 x, > k 进 y
    if (!id) {x = y = 0; return ;}
    if (tr[id].val <= k) {
        x = id;
        split(tr[id].rs,k,tr[id].rs,y);
        pushup(x);
    } else {
        y = id;
        split(tr[id].ls,k,x,tr[id].ls);
        pushup(y);
    }
}

void split(int id,int k,int &x,int &y) { // 前 k 个进 x
    if (!id) {x = y = 0; return;}
    if (tr[tr[id].ls].sz + 1 <= k) {
        x = id;
        split(tr[id].rs,k - tr[tr[id].ls].sz - 1,tr[id].rs,y);
        pushup(x);
    } else {
        y = id;
        split(tr[id].ls,k,x,tr[id].ls);
        pushup(x);
    }
}

void insert(int x){ // 插入
    int a,b; split(rt,x,a,b);
    rt = merge(merge(a,create(x)),b);
}

void erase(int x){ // 删除一个 x
    int a,b,c;
    split(rt,x - 1,a,b); split(b,x,b,c);
    b = merge(tr[b].ls,tr[b].rs);
    rt = merge(merge(a,b),c);
}

int kth(int id,int k){ // 第 k 小，不用 split
    while(true) {
        int L = tr[tr[id].ls].sz;
        if(k <= L) id = tr[id].ls;
        else if(k == L + 1) return tr[id].val;
        else k -= L + 1, id = tr[id].rs;
    }
}

int rnk(int x){ // x 的排名
    int a,b;
    split(rt,x - 1,a,b);
    int res = tr[a].sz+1;
    rt = merge(a,b);
    return res;
}

int pre(int x) { // 前驱：小于 x 的最大值
    int a, b;
    split(rt,x - 1,a,b);
    int res = kth(a,tr[a].sz);
    rt = merge(a,b);
    return res;
}

int nxt(int x) { // 后继：大于 x 的最小值
    int a, b;
    split(rt,x,a,b);
    int res = kth(b,1);
    rt = merge(a,b);
    return res;
}