n, m = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()
seq = set()
visited = [False for _ in range(n)]

def solve(picked, toPick):
    if toPick == 0:
        if tuple(picked) not in seq:
            for i in picked:
                print(i, end=' ')
            print()
            seq.add(tuple(picked))
        return
    for i in range(n):
        if not visited[i]:
            visited[i] = True
            picked.append(arr[i])
            solve(picked, toPick-1)
            visited[i] = False
            picked.pop()
solve([], m)