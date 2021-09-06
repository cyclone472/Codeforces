import sys
read = sys.stdin.readline

n = int(read())
seq = list(map(int, read().split()))
ans = [-1 for _ in range(len(seq))]
stack = []

for i in reversed(range(n)):
    cnt = seq[i]
    while stack:
        top = stack[-1]
        if cnt < top:
            ans[i] = top
            stack.append(cnt)
            break
        else:
            stack.pop()
    if not stack:
        stack.append(cnt)

for i in ans:
    print(i, end=' ')
