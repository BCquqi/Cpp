#include<iostream>
#include<cmath>
#include<set>
#include<cstring>
using namespace std;

#define min(a, b) ((a) < (b) ? (a) : (b))

namespace FastIO {
    static const int BUF_SIZE = 1 << 20;
    static char buf[BUF_SIZE];
    static int p1 = 0, p2 = 0;

    static inline char nc() {
        if (p1 == p2) {
            p2 = (int)fread(buf, 1, BUF_SIZE, stdin);
            p1 = 0;
            if (p2 == 0) return EOF;
        }
        return buf[p1++];
    }

    static inline int read() {
        int x = 0, f = 1;
        int ch = nc();
        while (ch != EOF && (ch < '0' || ch > '9')) {
            if (ch == '-') f = -1;
            ch = nc();
        }
        while (ch != EOF && ch >= '0' && ch <= '9') {
            x = x * 10 + ch - '0';
            ch = nc();
        }
        return x * f;
    }

    static char outbuf[BUF_SIZE];
    static int op = 0;

    static inline void flush() {
        fwrite(outbuf, 1, op, stdout);
        op = 0;
    }

    static inline void write(int x) {
        static char out[32];
        int len = 0;
        if (x < 0) {
            outbuf[op++] = '-';
            if (op == BUF_SIZE) flush();
            x = -x;
        }
        do {
            out[len++] = static_cast<char>(x % 10 + '0');
            x /= 10;
        } while (x > 0);
        while (len--) {
            outbuf[op++] = out[len];
            if (op == BUF_SIZE) flush();
        }
        outbuf[op++] = '\n';
        if (op == BUF_SIZE) flush();
    }

    static inline void writeIkaros() {
        const char* s = "Ikaros\n";
        for (int i = 0;i < 7;i++) {
            outbuf[op++] = s[i];
            if (op == BUF_SIZE) flush();
        }
    }
}

using FastIO::read;
using FastIO::write;
using FastIO::writeIkaros;

const int N = 1e5 + 5,len = 250,INF = 1e9,INF_DIS = 250;
const int maxnum = (100000 + len - 1) / len + 5;
int n,m,num = 0;
int a[N];
int l[maxnum],r[maxnum];
int off[len + 5];
unsigned char id[N + 5][maxnum];
int first[maxnum][len + 5],last[maxnum][len + 5];
unsigned char dis[maxnum][len * (len + 1) / 2 + 5];
short col[maxnum][len + 5];

void init(int bid) {
    set<int> s;
    for (int j = l[bid];j <= r[bid];j++) s.insert(a[j]);
    int idx = 0;
    for (int x : s) id[x][bid] = ++idx;
    memset(first[bid],0,(idx + 1) * sizeof(int));
    memset(last[bid],0,(idx + 1) * sizeof(int));
    short tmp[len + 5];
    for (int j = l[bid];j <= r[bid];j++) {
        int cid = id[a[j]][bid];
        tmp[j - l[bid]] = cid;
        col[bid][j - l[bid]] = cid;
        if (!first[bid][cid]) first[bid][cid] = j;
        last[bid][cid] = j;
    }
    memset(dis[bid],INF_DIS,len * (len + 1) / 2);
    for (int j = l[bid];j < r[bid];j++) {
        int id1 = tmp[j - l[bid]];
        for (int k = j + 1;k <= r[bid];k++) {
            int id2 = tmp[k - l[bid]];
            if (id1 == id2) continue;
            int d = k - j;
            int a = id1, b = id2;
            if (a > b) { int t = a; a = b; b = t; }
            int pos = off[a] + (b - a);
            if (d < dis[bid][pos])
                dis[bid][pos] = d;
        }
    }
}

inline void modify(int x,int y) {
    if (x == y) return ;
    for (int i = 1;i <= num;i++) {
        int idx = id[x][i],idy = id[y][i];
        if (idx == 0) continue;
        else if (idy == 0) id[x][i] = 0, id[y][i] = idx;
        else {
            if (first[i][idx] < first[i][idy]) first[i][idy] = first[i][idx];
            if (last[i][idx] > last[i][idy]) last[i][idy] = last[i][idx];
            int minid = idx < idy ? idx : idy;
            int maxid = idx < idy ? idy : idx;
            unsigned char *d = dis[i];
            for (int j = 1;j < minid;j++) {
                int p1 = off[j] + (idx - j);
                int p2 = off[j] + (idy - j);
                if (d[p1] < d[p2]) d[p2] = d[p1];
            }
            if (idy == maxid)
                for (int j = minid + 1;j < maxid;j++) {
                    int p1 = off[minid] + (j - minid);
                    int p2 = off[j] + (maxid - j);
                    if (d[p1] < d[p2]) d[p2] = d[p1];
                }
            else 
                for (int j = minid + 1;j < maxid;j++) {
                    int p1 = off[j] + (maxid - j);
                    int p2 = off[minid] + (j - minid);
                    if (d[p1] < d[p2]) d[p2] = d[p1];
                }
            for (int j = maxid + 1;j <= len;j++) {
                int p1 = off[idx] + (j - idx);
                int p2 = off[idy] + (j - idy);
                if (d[p1] < d[p2]) d[p2] = d[p1];
            }
            for (int j = 0;j <= r[i] - l[i];j++)
                if (col[i][j] == idx) col[i][j] = idy;
            id[x][i] = 0;
        }
    }
}

inline int query(int x,int y) {
    if (x == y) {
        for (int i = 1;i <= num;i++)
            if (id[x][i]) return 0;
        return INF;
    }
    int ans = INF;
    int lx = -INF,ly = -INF;
    for (int i = 1;i <= num;i++) {
        int idx = id[x][i],idy = id[y][i];
        if (idx && idy) {
            int a = idx < idy ? idx : idy;
            int b = idx < idy ? idy : idx;
            int d = dis[i][off[a] + (b - a)];
            ans = min(ans,d);
            ans = min(ans,first[i][idx] - ly);
            ans = min(ans,first[i][idy] - lx);
            if (ans == 0) return 0;
            lx = last[i][idx];
            ly = last[i][idy];
        } else if (idx) {
            ans = min(ans,first[i][idx] - ly);
            if (ans == 0) return 0;
            lx = last[i][idx];
        } else if (idy) {
            ans = min(ans,first[i][idy] - lx);
            if (ans == 0) return 0;
            ly = last[i][idy];
        }
    }
    return ans;
}

int main() {
    off[1] = 0;
    for (int i = 2;i <= len;i++)
        off[i] = off[i - 1] + (len - (i - 1) + 1);
    n = read(),m = read();
    num = (n + len - 1) / len;
    for (int i = 1;i <= n;i++) a[i] = read();
    for (int i = 1;i <= num;i++)
        l[i] = (i - 1) * len + 1, r[i] = min(i * len,n);
    for (int i = 1;i <= num;i++) init(i);
    int lastans = 0;
    while (m--) {
        int opt = read(),x = read(),y = read();
        x ^= lastans, y ^= lastans;
        if (opt == 1) modify(x,y);
        else {
            int ans = query(x, y);
            if (ans == INF) {
                writeIkaros();
                lastans = 0;
            } else {
                write(ans);
                lastans = ans;
            }
        }
    }
    FastIO::flush();
    return 0;
}