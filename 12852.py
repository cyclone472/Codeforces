from collections import deque

arr = [-1 for _ in range(1000001)]

q = deque()
q.append(1)
while q:
    i = q.popleft()
    if i+1 < 1000001 and arr[i+1] == -1:
        arr[i+1] = i
        q.append(i+1)
    if 2*i < 1000001 and arr[2*i] == -1:
        arr[2*i] = i
        q.append(2*i)
    if 3*i < 1000001 and arr[3*i] == -1:
        arr[3*i] = i
        q.append(3*i)

x = int(input())
ans = [x]

while x != 1:
    ans.append(arr[x])
    x = arr[x]
print(len(ans)-1)
for i in ans:
    print(i, end=' ')