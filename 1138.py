from itertools import permutations

N = int(input())
rank = list(map(int, input().split()))
permute = permutations([i for i in range(N)], N)

# 모든 조합을 만들어 놓고 키 큰 사람 정보와 맞는지 확인
for order in permute:
    isAnswer = True
    for i in range(N):
        taller = 0
        for j in range(0, i):
            if order[i] < order[j]:
                taller += 1
        if rank[order[i]] != taller:
            isAnswer = False
            break
    
    if isAnswer:
        for i in order:
            print(i+1, end=' ')
        print()
        break
