n,r,c = map(int, input().split())

ans = 0
while n != 0:
    n -= 1
    blen = 2**n
    if r < blen and c < blen:
        continue
    elif r < blen and c >= blen:
        ans += (blen*blen)
        c -= blen
    elif r >= blen and c < blen:
        ans += (blen*blen)*2
        r -= blen
    else:
        ans += (blen*blen)*3
        c -= blen
        r -= blen
print(ans)