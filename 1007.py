import math
t = int(input())
point = []

def dfs(choice, toPick, cnt, n):
    if n - cnt < toPick:
        return 1<<50
    if toPick == 0:
        tx, ty = 0, 0
        for x, y in point:
            tx += (x if (choice&1) == 1 else -x)
            ty += (y if (choice&1) == 1 else -y)
            choice >>= 1
        return math.sqrt(tx*tx + ty*ty)
    
    ret = 1<<50
    ret = min(ret, dfs(choice|(1<<cnt), toPick-1, cnt+1, n))
    ret = min(ret, dfs(choice, toPick, cnt+1, n))
    return ret


for _ in range(t):
    n = int(input())
    for _ in range(n):
        x, y = map(int, input().split())
        point.append((x,y))

    # 벡터의 도착지가 될 원소를 N/2개 선택
    print(dfs(0, n//2, 0, n))
    point.clear()