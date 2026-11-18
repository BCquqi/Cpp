#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

static const int BASE = 1000000000;
static const int LIMB_CNT = 56;
static const int NTT_LEN = 128;
static const int MOD = 998244353;
static const int G = 3;

static int fa[NTT_LEN], fb[NTT_LEN];
static int rev[NTT_LEN];
static unsigned int A[LIMB_CNT], R[LIMB_CNT];

inline int mod_pow(int a, int b) {
    int r = 1;
    while (b) {
        if (b & 1) r = (long long)r * a % MOD;
        a = (long long)a * a % MOD;
        b >>= 1;
    }
    return r;
}

void init_rev() {
    for (int i = 0; i < NTT_LEN; ++i) {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) ? (NTT_LEN >> 1) : 0);
    }
}

void ntt(int *a, int invert) {
    for (int i = 0; i < NTT_LEN; ++i) {
        if (i < rev[i]) {
            int tmp = a[i];
            a[i] = a[rev[i]];
            a[rev[i]] = tmp;
        }
    }
    for (int len = 2; len <= NTT_LEN; len <<= 1) {
        int wlen = mod_pow(G, (MOD - 1) / len);
        if (invert) wlen = mod_pow(wlen, MOD - 2);
        for (int i = 0; i < NTT_LEN; i += len) {
            int w = 1;
            int half = len >> 1;
            for (int j = 0; j < half; ++j) {
                int u = a[i + j];
                int v = (long long)a[i + j + half] * w % MOD;
                int x = u + v;
                if (x >= MOD) x -= MOD;
                int y = u - v;
                if (y < 0) y += MOD;
                a[i + j] = x;
                a[i + j + half] = y;
                w = (long long)w * wlen % MOD;
            }
        }
    }
    if (invert) {
        int inv_n = mod_pow(NTT_LEN, MOD - 2);
        for (int i = 0; i < NTT_LEN; ++i) {
            a[i] = (long long)a[i] * inv_n % MOD;
        }
    }
}

void multiply(int square) {
    for (int i = 0; i < NTT_LEN; ++i) {
        fa[i] = 0;
        fb[i] = 0;
    }
    for (int i = 0; i < LIMB_CNT; ++i) {
        fa[i] = A[i];
        if (!square) fb[i] = R[i];
    }
    if (square) {
        for (int i = 0; i < LIMB_CNT; ++i) fb[i] = fa[i];
    }
    ntt(fa, 0);
    ntt(fb, 0);
    for (int i = 0; i < NTT_LEN; ++i) {
        fa[i] = (long long)fa[i] * fb[i] % MOD;
    }
    ntt(fa, 1);
    long long carry = 0;
    for (int i = 0; i < LIMB_CNT; ++i) {
        long long cur = carry + fa[i];
        R[i] = cur % BASE;
        carry = cur / BASE;
    }
}

void quick_pow(int p) {
    for (int i = 0; i < LIMB_CNT; ++i) {
        R[i] = 0;
        A[i] = 0;
    }
    R[0] = 1;
    A[0] = 2;
    while (p) {
        if (p & 1) {
            multiply(0);
        }
        multiply(1);
        for (int i = 0; i < LIMB_CNT; ++i) A[i] = R[i];
        p >>= 1;
    }
}

inline int read_int() {
    int x = 0;
    char c = getchar_unlocked();
    while (c < '0' || c > '9') c = getchar_unlocked();
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar_unlocked();
    }
    return x;
}

inline void write_int(int x) {
    if (x == 0) {
        putchar_unlocked('0');
        return;
    }
    char s[12];
    int len = 0;
    while (x) {
        s[len++] = '0' + (x % 10);
        x /= 10;
    }
    while (len--) putchar_unlocked(s[len]);
}

int main() {
    int p = read_int();
    int digits = (int)(p * 0.3010299956639811952137389) + 1;
    write_int(digits);
    putchar_unlocked('\n');
    init_rev();
    quick_pow(p);
    R[0] -= 1;
    char out[505];
    int pos = 0;
    int started = 0;
    for (int i = LIMB_CNT - 1; i >= 0; --i) {
        if (!started && R[i] == 0) continue;
        if (!started) {
            started = 1;
            pos += sprintf(out + pos, "%u", R[i]);
        } else {
            pos += sprintf(out + pos, "%09u", R[i]);
        }
    }
    if (!started) out[pos++] = '0';
    out[pos] = '\0';
    int len = pos;
    if (len < 500) {
        char padded[505];
        for (int i = 0; i < 500 - len; ++i) padded[i] = '0';
        for (int i = 0; i < len; ++i) padded[500 - len + i] = out[i];
        padded[500] = '\0';
        for (int i = 0; i < 500; ++i) out[i] = padded[i];
        out[500] = '\0';
    }
    for (int i = 0; i < 500; i += 50) {
        for (int j = 0; j < 50; ++j) {
            putchar_unlocked(out[i + j]);
        }
        putchar_unlocked('\n');
    }
    return 0;
}