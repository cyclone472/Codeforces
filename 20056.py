import sys
read = sys.stdin.readline

def allOdd(list):
    for i in list:
        if i % 2 == 0:
            return False
    return True

def allEven(list):
    for i in list:
        if i % 2 == 1:
            return False
    return True

def move(balls, board, dx, dy):
    # 모든 볼이 이동
    for i, ball in enumerate(balls):
        cx = ball[1]
        cy = ball[0]
        mass = ball[2]
        # 보드에서 현재 볼을 지우고
        board[cy][cx][0] -= 1
        for j, x in enumerate(board[cy][cx][1]):
            if x == ball:
                del board[cy][cx][1][j]
                break

        dir = ball[4];
        speed = ball[3]
        nx = (ball[1] + speed * dx[dir]) % n
        ny = (ball[0] + speed * dy[dir]) % n
        balls[i][0] = ny
        balls[i][1] = nx

        # 새로운 위치에 다시 볼 생성
        board[ny][nx][0] += 1
        board[ny][nx][1].append([ny, nx, mass, speed, dir])
    
    for y in range(n):
        for x in range(n):
            if board[y][x][0] > 1:
                new_mass = 0
                new_speed = 0
                dir_arr = []
                for fire in board[y][x][1]:
                    new_mass += fire[2]
                    new_speed += fire[3]
                    dir_arr.append(fire[4])
                new_mass = new_mass // 5
                new_speed = new_speed // board[y][x][0]
                
                if new_mass == 0:
                    board[y][x][0] = 0
                    for ball in board[y][x][1]:
                        for i, b in enumerate(balls):
                            if b == ball:
                                del balls[i]
                                break
                    board[y][x][1] = []
                    continue
                
                for ball in board[y][x][1]:
                    for i, b in enumerate(balls):
                        if b == ball:
                            del balls[i]
                            break

                board[y][x][0] = 4
                board[y][x][1] = []
                if allOdd(dir_arr) or allEven(dir_arr):
                    for i in range(0, 8, 2):
                        board[y][x][1].append([y, x, new_mass, new_speed, i])
                        balls.append([y, x, new_mass, new_speed, i])
                else:
                    for i in range(1, 9, 2):
                        board[y][x][1].append([y, x, new_mass, new_speed, i])
                        balls.append([y, x, new_mass, new_speed, i])
    return    

dx = [0, 1, 1, 1, 0, -1, -1, -1]
dy = [-1, -1, 0, 1, 1, 1, 0, -1]

n, m, k = map(int, read().split())
balls = []
# 각 칸에 볼이 몇 개 있는지 표시
board = [[[0, []] for _ in range(n)] for _ in range(n)]
for i in range(m):
    y, x, mass, speed, dir = map(int, read().split())
    balls.append([y-1, x-1, mass, speed, dir])
    board[y-1][x-1][0] = 1
    board[y-1][x-1][1].append([y-1, x-1, mass, speed, dir])

for i in range(k):
    move(balls, board, dx, dy)
    print('i is :', str(i))
    for y in range(n):
        for x in range(n):
            for ball in board[y][x][1]:
                print(ball)

ans = 0
for y in range(n):
    for x in range(n):
        for ball in board[y][x][1]:
            print(ball)
            ans += ball[2]
print (ans)