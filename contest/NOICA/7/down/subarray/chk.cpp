#include "./testlib.h"

#include <string>
#include <vector>

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);
    setName("subarray special judge");

    const int n = inf.readInt();
    std::vector<long long> expected(n);
    for (int i = 0; i < n; ++i) {
        expected[i] = inf.readLong();
    }

    std::vector<int> a(n), previous_less(n), stack;
    stack.reserve(n);
    for (int i = 0; i < n; ++i) {
        a[i] = ouf.readInt(1, n, "A[" + std::to_string(i + 1) + "]");
    }
    if (!ouf.seekEof()) {
        quitf(_pe, "Extra tokens after the expected %d integers", n);
    }

    for (int i = 0; i < n; ++i) {
        while (!stack.empty() && a[stack.back()] >= a[i]) {
            stack.pop_back();
        }
        previous_less[i] = stack.empty() ? -1 : stack.back();
        stack.push_back(i);
    }

    stack.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (!stack.empty() && a[stack.back()] >= a[i]) {
            stack.pop_back();
        }
        const int next_less = stack.empty() ? n : stack.back();
        const long long actual = 1LL * (i - previous_less[i]) * (next_less - i);
        if (actual != expected[i]) {
            quitf(_wa,
                  "B[%d] is %lld for the submitted array, but %lld is required",
                  i + 1, actual, expected[i]);
        }
        stack.push_back(i);
    }

    quitf(_ok, "Accepted: the submitted array reconstructs all %d values", n);
}
