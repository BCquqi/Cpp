for (int i = 1;i <= n;i++)
    for (auto j : G[i]) {
        int x = id[i],y = id[j];
        long long hash = 1ll * x * N + y;
        if (x != y && s.count(hash) == 0) {
            in[y]++,out[x]++;
            s.insert(hash);
        }
    }