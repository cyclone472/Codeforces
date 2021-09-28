from itertools import combinations
from collections import deque

seat = []
for _ in range(5):
    seat.append(input())

ans = 0
for pick in combinations([i for i in range(25)], 7):
    # pick에 속한 모든 원소가 인접한지 check
    q = deque()
    picked = [False for _ in range(25)]
    visited = [False for _ in range(25)]
    for i in pick:
        picked[i] = True
    q.append(pick[0])
    visited[pick[0]] = True
    adj = 1
    dasom = (1 if seat[pick[0]//5][pick[0]%5] == 'S' else 0)
    while q:
        coord = q.popleft()
        for dir in [-1, 1, -5, 5]:
            nc = coord + dir
            if nc < 0 or nc >= 25 or visited[nc] or not picked[nc]:
                continue
            elif dir == 1 and nc % 5 == 0: continue
            elif dir == -1 and nc % 5 == 4: continue

            q.append(nc)
            visited[nc] = True
            adj += 1
            dasom += (1 if seat[nc//5][nc%5] == 'S' else 0)
    if adj == 7 and dasom >= 4:
        ans += 1

print(ans)