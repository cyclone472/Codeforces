import sys
sys.setrecursionlimit(100000)

def isPalindrome(s, e):
    while s < e:
        if st[s] != st[e]:
            return False
        s += 1
        e -= 1
    return True

def solve(s):
    if s >= n:
        return 0
    elif dp[s] != INF:
        return dp[s]
    
    ret = INF
    for i in pal[s]:
        ret = min(ret, solve(i+1) + 1)
    dp[s] = ret
    return ret

st = input()
n = len(st)
INF = 3333
pal = [[] for _ in range(n)]
dp = [INF for _ in range(n)]
for i in range(n):
    for j in range(i, n):
        if isPalindrome(i, j):
            pal[i].append(j)

print(solve(0))