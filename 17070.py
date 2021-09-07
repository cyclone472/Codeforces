from collections import deque

N = int(input())
mv = [(-1,-1), (0,-1), (-1,0)]
house = [[0]*(N+1) for _ in range(N+1)]
dp = [[[0]*(N+1) for _ in range(N+1)] for _ in range(3)]
for i in range(1,N+1):
    house[i][1:N+1] = list(map(int, input().split()))
dp[1][1][2] = 1

def canMove(y, x, dir):
    if dir == 1 or dir == 2:
        return house[y][x] == 0
    else:
        return house[y][x] == 0 and house[y-1][x] == 0 and \
            house[y][x-1] == 0

for y in range(1,N+1):
    for x in range(1,N+1):
        if (x,y) == (1,1) or (x,y) == (2,1):
            continue
        for dir in range(3):
            if not canMove(y, x, dir):
                continue
            for j in range(3):
                if dir * j == 2:
                    continue
                ny = y + mv[dir][0]
                nx = x + mv[dir][1]
                dp[dir][y][x] += dp[j][ny][nx]

ans = 0
for i in range(3):
    ans += dp[i][N][N]
print(ans)