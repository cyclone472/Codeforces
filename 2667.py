from collections import deque

def bfs(x, y):
    visited = [[False]*n for _ in range(n)]
    ret = 1
    q = deque()
    visited[y][x] = True
    q.append((x, y))
    while q:
        cx, cy = q.popleft()
        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]
            if nx < 0 or nx >= n or ny < 0 or ny >= n \
                or visited[ny][nx] or arr[ny][nx] != '1':
                continue
            q.append((nx,ny))
            visited[ny][nx] = True
            arr[ny][nx] = '2'
            ret += 1
    return ret

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
n = int(input())
arr = [[] for _ in range(n)]
for i in range(n):
    arr[i] = list(input())

ans = []
for y in range(n):
    for x in range(n):
        if arr[y][x] == '1':
            ans.append(bfs(x, y))
print(len(ans))
ans.sort()
for elem in ans:
    print(elem)