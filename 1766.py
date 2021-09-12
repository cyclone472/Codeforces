import sys
import heapq
read = sys.stdin.readline

N, M = map(int, read().split())
G = [[] for _ in range(N)]
numParent = [0 for _ in range(N)]
for _ in range(M):
    u, v = map(int, read().split())
    G[u-1].append(v-1)
    numParent[v-1] += 1

ret = []
pq = []
for i, par in enumerate(numParent):
    if par == 0:
        heapq.heappush(pq, i)

while pq:
    cnt = heapq.heappop(pq)
    ret.append(cnt)
    for next in G[cnt]:
        numParent[next] -= 1
        if numParent[next] == 0:
            heapq.heappush(pq, next)

for i in ret:
    print(i+1, end=' ')
