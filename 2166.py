import sys
read = sys.stdin.readline

n = int(read())
arr = []
for _ in range(n):
    x, y = map(int, read().split())
    arr.append((x, y))

ans = 0
for i in range(len(arr)-1):
    ans += (arr[i][0]*arr[i+1][1]) - (arr[i][1]*arr[i+1][0])
ans += (arr[-1][0]*arr[0][1] - arr[0][0]*arr[-1][1])
ans = abs(ans) / 2
print(round(ans, 1))