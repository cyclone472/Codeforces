import sys
from bisect import bisect_left
read = sys.stdin.readline

MAX = 1234567890

if __name__ == "__main__":
    n = int(read())
    seq = list(map(int, read().split()))
    dp = [MAX]*n
    cand = [[] for _ in range(n)]

    dp[0] = seq[0]
    cand[0].append((0, seq[0]))
    for i in range(1, n):
        cnt = bisect_left(dp, seq[i])
        if dp[cnt] == MAX or dp[cnt] > seq[i]:
            dp[cnt] = seq[i]
        cand[cnt].append((i, seq[i]))
    for l in cand:
        l.sort()
    # print(cand)
    len = bisect_left(dp, 1234567890)
    print(len)
    ans_seq = []
    prev_idx = 123456789
    # 뒤에서부터 원소를 가져오되 i-1보다 작은 것 중 가장 index가 큰 것 가져옴
    for i in reversed(range(len)):
        next = bisect_left(cand[i], (prev_idx, 1)) - 1
        prev_idx = cand[i][next][0]
        ans_seq.append(cand[i][next][1])
    for i in reversed(ans_seq):
        print(i, end=' ')
