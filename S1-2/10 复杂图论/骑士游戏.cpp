#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstdint>
#include<sys/mman.h>
#include<sys/stat.h>
#include<unistd.h>
using namespace std;

uint8_t* str;
uint8_t* bufEnd;
#define gc() (str < bufEnd ? *str++ : 0)

long long readint() {
    long long k = 0;
    int f = 1;
    uint8_t c = gc();
    while (c != '-' && (c < '0' || c > '9')) c = gc();
    if (c == '-') f = -1, c = gc();
    while (c >= '0' && c <= '9') {
        k = k * 10 + c - '0';
        c = gc();
    }
    return k * f;
}

const int N = 2e5 + 5;
int r[N],n;
long long s[N],k[N],dis[N],sum[N],sent[N];
bool vis[N];
vector<int> G[N],rG[N];
int q[N],head,tail,cnt;

inline void put(long long d) {
    if (d < 0) putchar_unlocked('-'),d = -d;
    if (d > 9) put(d / 10);
    putchar_unlocked(d % 10 + '0');
}

inline void push(int x) {
    q[tail] = x;
    tail = (tail + 1) % n;
    cnt++;
    vis[x] = true;
}

inline int pop() {
    int x = q[head];
    head = (head + 1) % n;
    cnt--;
    vis[x] = false;
    return x;
}

inline void spfa() {
    head = tail = cnt = 0;

    for (int i = 1;i <= n;i++) {
        dis[i] = sent[i] = k[i];
        sum[i] = s[i];
        for (int w : G[i]) sum[i] += k[w];
    }

    for (int i = 1;i <= n;i++)
        if (sum[i] < dis[i]) dis[i] = sum[i],push(i);

    while (cnt) {
        int u = pop();
        long long delta = dis[u] - sent[u];
        if (delta == 0) continue;
        sent[u] = dis[u];

        for (int v : rG[u]) {
            sum[v] += delta;
            if (sum[v] < dis[v]) {
                dis[v] = sum[v];
                if (!vis[v]) push(v);
            }
        }
    }
}

int main() {
    struct stat z;
    fstat(0,&z);
    str = (uint8_t*)mmap(NULL,z.st_size,PROT_READ,MAP_PRIVATE,0,0);
    bufEnd = str + z.st_size;

    n = readint();
    for (int u = 1;u <= n;u++) {
        s[u] = readint(),k[u] = readint(),r[u] = readint();
        for (int j = 1;j <= r[u];j++) {
            int v = readint();
            G[u].push_back(v);
            rG[v].push_back(u);
        }
    }

    spfa();
    put(dis[1]);
    return 0;
}