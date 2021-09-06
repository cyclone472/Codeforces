visited = [[False]*6 for _ in range(6)]
dx = [-2, -1, 1, 2, 2, 1, -1, -2]
dy = [-1, -2, -2, -1, 1, 2, 2, 1]
prev_x = -1
prev_y = -1
start_x = -1
start_y = -1
isValid = True
for i in range(36):
    s = input()
    x = ord(s[0]) - ord("A")
    y = 6 - int(s[1])
    visited[y][x] = True
    if prev_x == -1 and prev_y == -1:
        start_x = x; prev_x = x
        start_y = y; prev_y = y
        continue
    valid = False
    for i in range(8):
        if prev_x + dx[i] == x and prev_y + dy[i] == y:
            valid = True
            break
    if not valid:
        isValid = False
        break
    prev_x = x
    prev_y = y

for i in range(6):
    for j in range(6):
        if not visited[i][j]:
            isValid = False
            break

reach_first = False
for i in range(8):
    if prev_x + dx[i] == start_x and prev_y + dy[i] == start_y:
        reach_first = True
        break
if isValid and reach_first:
    print("Valid")
else:
    print("Invalid")