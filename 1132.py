N = int(input())
alpha = []
for _ in range(N):
    alpha.append(input())

score = [[0, i] for i in range(10)]
appear_first = [False for _ in range(10)]
for num in alpha:
    appear_first[ord(num[0])-65] = True
    for i, ch in enumerate(reversed(num)):
        score[ord(ch)-65][0] += 10**i
score.sort()

# 먼저 0을 결정하고 나머지를 합산
for i, [scores, num] in enumerate(score):
    if not appear_first[num]:
        del score[i]
        break
ans = 0
for i, [scores, num] in enumerate(score):
    ans += (i+1) * scores
print(ans)