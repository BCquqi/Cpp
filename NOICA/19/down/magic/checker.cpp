#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    const int T = inf.readInt();

    for (int tc = 1; tc <= T; ++tc) {
        const string expected = ans.readToken();
        const string verdict = ouf.readToken();
        if (verdict != "Yes" && verdict != "No") {
            quitf(_wa, "case %d: the first token must be Yes or No", tc);
        }
        if (verdict != expected) {
            quitf(_wa, "case %d: the existence judgment is wrong", tc);
        }

        const int n = inf.readInt();
        const int m = inf.readInt();
        vector<vector<long long>> w(n + 1, vector<long long>(m + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) w[i][j] = inf.readLong();
        }

        if (verdict == "No") continue;

        int x = ouf.readInt();
        int y = ouf.readInt();
        const string path = ouf.readToken();
        const long long cells = 1LL * n * m;
        if ((long long)path.size() != cells - 1) {
            quitf(_wa, "case %d: path length is %d, expected %lld", tc,
                  (int)path.size(), cells - 1);
        }
        for (char c : path) {
            if (c != 'U' && c != 'D' && c != 'L' && c != 'R') {
                quitf(_wa, "case %d: invalid direction character", tc);
            }
        }

        vector<unsigned char> visited((size_t)cells, 0);
        long long value = 0;
        for (long long step = 0; step < cells; ++step) {
            if (x < 1 || x > n || y < 1 || y > m) {
                quitf(_wa, "case %d: move %lld leaves the board", tc, step);
            }
            const size_t id = (size_t)(x - 1) * m + (y - 1);
            if (visited[id]) {
                quitf(_wa, "case %d: cell (%d,%d) is visited more than once", tc, x, y);
            }
            visited[id] = 1;
            value += w[x][y];
            if (value < 0) {
                quitf(_wa, "case %d: prefix sum becomes negative at visit %lld", tc, step + 1);
            }

            if (step + 1 == cells) break;
            switch (path[(size_t)step]) {
                case 'U': --x; break;
                case 'D': ++x; break;
                case 'L': --y; break;
                case 'R': ++y; break;
            }
        }
    }

    if (!ouf.seekEof()) quitf(_wa, "extra output after the last test case");
    quitf(_ok, "all constructions are valid");
}
