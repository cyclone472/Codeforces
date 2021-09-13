import sys
import heapq
read = sys.stdin.readline
sys.setrecursionlimit(10**6)

def isUsed(prev, visited, n, g, h):
    if not visited[n]:
        visited[n] = True
        for next in prev[n]:
            if (g, h) == (n, next) or (g, h) == (next, n):
                return True
            if isUsed(prev, visited, next, g, h):
                return True
    return False

T = int(read())
INF = 987654321
for _ in range(T):
    # Get input
    n, m, t = map(int, read().split())
    s, g, h = map(int, read().split())
    s -= 1; g -= 1; h -= 1
    G = [[] for _ in range(n)]
    end = []
    for _ in range(m):
        a, b, d = map(int, read().split())
        G[a-1].append((b-1, d))
        G[b-1].append((a-1, d))
    for _ in range(t):
        end.append(int(read()))

    # Dijkstra
    dist = [INF for _ in range(n)]
    prev = [[] for _ in range(n)]
    pq = []
    dist[s] = 0
    heapq.heappush(pq, (0, s))
    while pq:
        val, here = heapq.heappop(pq)
        if dist[here] < val:
            continue

        for there, cost in G[here]:
            if dist[there] < val + cost:
                continue
            elif dist[there] == val + cost:
                prev[there].append(here)
                continue
            dist[there] = cost + val
            prev[there] = [here]
            heapq.heappush(pq, (cost + val, there))

    ans = []
    for i in end:
        visited = [False for _ in range(n)]
        if isUsed(prev, visited, i-1, g, h):
            ans.append(i)
    ans.sort()
    print(*ans)