import sys
read = sys.stdin.readline

def dist(x1, y1, x2, y2):
    return (x2-x1 if x1 < x2 else x1-x2) + (y2-y1 if y1 < y2 else y1-y2)

n = int(read())
INF = (1 << 62)
dp = [[INF]*(4) for _ in range(n+1)]
dp[0] = [0,0,0,0]
dx = [-1, 0, 1, 0]; dy = [0, 1, 0, -1]
sx, sy = map(int, read().split())
tmpx, tmpy = map(int, read().split())
for i in range(4):
    dp[1][i] = dist(sx, sy, tmpx+dx[i], tmpy+dy[i])

prev_x, prev_y = (tmpx, tmpy)
for i in range(2,n+1):
    cx, cy = map(int, read().split())
    for dir1 in range(4):
        px = prev_x + dx[dir1]
        py = prev_y + dy[dir1]
        for dir2 in range(4):
            nx = cx + dx[dir2]
            ny = cy + dy[dir2]
            dp[i][dir2] = min(dp[i][dir2], dp[i-1][dir1] + dist(px,py,nx,ny))
    prev_x = cx
    prev_y = cy

ans = INF
for i in range(4):
    ans = min(ans, dp[n][i])
print(ans)