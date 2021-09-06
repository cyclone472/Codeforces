def nearOcean(x, y):
    ret = 0
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if arr[ny][nx] == '.':
            ret += 1
    if ret >= 3:
        return True
    else:
        return False

r,c = map(int, input().split())
arr = [['.']*(c+2) for _ in range(r+2)]
ans = [['.']*(c+2) for _ in range(r+2)]
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

for y in range(1, r+1):
    s = input()
    for x in range(1, c+1):
        arr[y][x] = s[x-1]

for y in range(1, r+1):
    for x in range(1, c+1):
        if arr[y][x] == 'X' and not nearOcean(x, y):
            ans[y][x] = 'X'
        else:
            ans[y][x] = '.'

sx = 0; ex = c+1
sy = 0; ey = r+1
for y in range(r+2):
    allOcean = True
    for x in range(c+2):
        if ans[y][x] == 'X':
            allOcean = False
            break
    if allOcean:
        sy += 1
    else:
        break

for y in reversed(range(r+2)):
    allOcean = True
    for x in range(c+2):
        if ans[y][x] == 'X':
            allOcean = False
            break
    if allOcean:
        ey -= 1
    else:
        break

for x in range(c+2):
    allOcean = True
    for y in range(r+2):
        if ans[y][x] == 'X':
            allOcean = False
            break
    if allOcean:
        sx += 1
    else:
        break

for x in reversed(range(c+2)):
    allOcean = True
    for y in range(r+2):
        if ans[y][x] == 'X':
            allOcean = False
            break
    if allOcean:
        ex -= 1
    else:
        break

for y in range(sy, ey+1):
    for x in range(sx, ex+1):
        print(ans[y][x], end='')
    print()