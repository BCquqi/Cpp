import random, subprocess

def brute(n, pts):
    board = [[1 if ((i+j) & 1) else -1 for j in range(1, n+1)] for i in range(1, n+1)]
    for x, y in pts:
        board[x-1][y-1] *= -1
    ans = 0
    for x1 in range(1, n+1):
        for x2 in range(x1, n+1):
            for y1 in range(1, n+1):
                for y2 in range(y1, n+1):
                    s = 0
                    for i in range(x1, x2+1):
                        for j in range(y1, y2+1):
                            s += board[i-1][j-1]
                    if abs(s) > ans:
                        ans = abs(s)
    return ans

def solve_case(n, pts):
    inp = f'1\n{n} {len(pts)}\n' + ''.join(f'{x} {y}\n' for x, y in pts)
    p = subprocess.run(['two_fix.exe'], input=inp.encode(), stdout=subprocess.PIPE, stderr=subprocess.PIPE, check=False)
    if p.returncode != 0:
        return None
    out = p.stdout.decode().strip().splitlines()
    return int(out[-1])

for n in range(1, 9):
    for _ in range(80):
        pts = []
        used = set()
        k = random.randint(0, min(12, n*n))
        while len(pts) < k:
            x = random.randint(1, n)
            y = random.randint(1, n)
            if (x, y) not in used:
                used.add((x, y))
                pts.append((x, y))
        got = solve_case(n, pts)
        expect = brute(n, pts)
        if got != expect:
            print('Mismatch', n, pts, got, expect)
            raise SystemExit(1)
print('random-ok')
