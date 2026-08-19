#include<iostream>
#include<ctime>
#include<random>
#include<algorithm>
#include<stack>
using namespace std;

const int N = 1e5 + 5;

mt19937 gen(time(0));
struct Node {int ls,rs,sz,fix,val,fa; bool rev;} tr[N];
struct Input {int id,val;} p[N];
stack<int> st;
int idx = 0,rt;

int create(int id) {tr[++idx] = {0,0,1,(int)gen(),id,false}; return idx;}

void pushup(int id) {
    tr[id].sz = tr[tr[id].ls].sz + tr[tr[id].rs].sz + 1;
    if (tr[id].ls) tr[tr[id].ls].fa = id;
    if (tr[id].rs) tr[tr[id].rs].fa = id;
}

void pushdown(int id) {
    if (!tr[id].rev) return ;
    tr[id].rev = false;
    swap(tr[id].ls,tr[id].rs);
    if (tr[id].ls) tr[tr[id].ls].rev = !tr[tr[id].ls].rev;
    if (tr[id].rs) tr[tr[id].rs].rev = !tr[tr[id].rs].rev;
    return ;
}

int merge(int x,int y) {
    if (!x || !y) return x + y;
    pushdown(x); pushdown(y);
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

void split(int id,int k,int &x,int &y) { // 前 k 个进 x
    if (!id) {x = y = 0; return;}
    pushdown(id);
    if (tr[tr[id].ls].sz + 1 <= k) {
        x = id;
        split(tr[id].rs,k - tr[tr[id].ls].sz - 1,tr[id].rs,y);
        pushup(x);
    } else {
        y = id;
        split(tr[id].ls,k,x,tr[id].ls);
        pushup(y);
    }
}

int rnk(int x){ // x 的排名
    while (!st.empty()) st.pop();
    int cur = x;
    for (int cur = x;cur;cur = tr[cur].fa) st.push(cur);
    while (!st.empty()) {
        pushdown(st.top());
        st.pop();
    }
    int ret = tr[tr[x].ls].sz + 1;
    for (int cur = x;cur;cur = tr[cur].fa)
        if (cur == tr[tr[cur].fa].rs)
            ret += tr[tr[tr[cur].fa].ls].sz + 1;
    return ret;
}

void reverse(int l,int r) {
    int a,b,c;
    split(rt,l - 1,a,b);
    split(b,r - l + 1,b,c);
    tr[b].rev = !tr[b].rev;
    rt = merge(merge(a,b),c);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> p[i].val;
        p[i].id = i;
    }
    sort(p + 1,p + n + 1,[](Input x,Input y) {return x.val != y.val ? x.val < y.val : x.id < y.id;});
    for (int i = 1;i <= n;i++) rt = merge(rt,create(i));
    for (int i = 1;i <= n;i++) {
        int rank = rnk(p[i].id);
        cout << rank << ' ';
        reverse(i,rank);
    }
    cout << endl;
    return 0;
}