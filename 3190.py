from collections import deque

N = int(input())
K = int(input())
snake = deque([(0,0)])
# 빈 보드면 0, 사과면 1, 자기 자신의 몸이면 2
board = [[0]*N for _ in range(N)]
board[0][0] = 2
# 왼쪽으로 방향 전환하려면 i-1번째 방향 사용
# 오른쪽으로 방향 전환하려면 i+1번째 방향 사용
dir = [(0, 1), (1, 0), (0, -1), (-1, 0)]
for _ in range(K):
    y, x = map(int, input().split())
    board[y-1][x-1] = 1

L = int(input())
rot = deque()
for _ in range(L):
    x, c = input().split()
    rot.append((int(x), c))

sec = 0; y = 0; x = 0; ptr = 0
while True:
    sec += 1
    y += dir[ptr][0]
    x += dir[ptr][1]
    if y < 0 or y >= N or x < 0 or x >= N or board[y][x] == 2:
        break
    if board[y][x] == 0:
        ty, tx = snake.pop()
        board[ty][tx] = 0
    snake.appendleft((y, x))
    board[y][x] = 2

    if rot and rot[0][0] == sec:
        ptr = ((ptr+1)%4 if rot[0][1] == 'D' else (ptr-1)%4)
        rot.popleft()
print(sec)
