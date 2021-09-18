import sys
read = sys.stdin.readline

n = int(read())
maxScore = [[0,0,0],[0,0,0]]
minScore = [[0,0,0],[0,0,0]]

for i in range(n):
    minScore[i%2] = [10**6,10**6,10**6]
    dp = list(map(int, read().split()))
    for j in range(3):
        for k in range(-1,2):
            if j+k < 0 or j+k >= 3:
                continue
            maxScore[i%2][j] = max(maxScore[i%2][j], maxScore[(i+1)%2][j+k] + dp[j])
            minScore[i%2][j] = min(minScore[i%2][j], minScore[(i+1)%2][j+k] + dp[j])

print(max(maxScore[(n+1)%2]), min(minScore[(n+1)%2]))