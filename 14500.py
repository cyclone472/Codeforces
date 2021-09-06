
tetros = [[(0,0), (0,1), (0,2), (0,3)], [(0,0), (1,0), (2,0), (3,0)], # ㅡ,ㅣ
         [(0,0), (0,1), (1,0), (1,1)],                                # ㅁ
         [(0,0), (1,0), (2,0), (2,1)], [(0,0), (0,1), (-1,1), (-2,1)], # ㄴ, 
         [(0,0), (1,0), (2,0), (0,1)], [(0,0), (1,0), (2,0), (-1,0)],
         [(0,0), (1,0), (1,1), (1,2)],
         [(0,0), (1,0), (2,0), (1,1)]]

def putTetro(row, col):
    ret = -1
    for tetro in tetros:
        score = 0
        for dy, dx in tetro:
            nx = row + dx
            ny = col + dy
            if nx < 0 or nx >= m or ny < 0 or ny >= n:
                score = -1
                break
            score += board[ny][nx]
        ret = max(ret, score)
    return ret

if __name__ == "__main__":
    n, m = map(int, input().split())
    board = []
    for i in range(n):
        board.append(list(map(int, input().split())))

    ans = -1
    for row in range(m):
        for col in range(n):
            ans = max(ans, putTetro(row, col))
    print(ans)
