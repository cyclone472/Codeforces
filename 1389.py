n,m = map(int, input().split())
g = [[123456789 for _ in range(n)] for _ in range(n)]
for i in range(m):
    a,b = map(int, input().split())
    g[a-1][b-1] = 1
    g[b-1][a-1] = 1

for k in range(n):
    for i in range(n):
        for j in range(n):
            g[i][j] = min(g[i][j], g[i][k]+g[k][j])

kevin = [0 for _ in range(n)]
min_val = 123456789
ans = -1
for i in range(n):
    kevin[i] += sum(g[i])
    if kevin[i] < min_val:
        min_val = kevin[i]
        ans = i
print(ans+1)