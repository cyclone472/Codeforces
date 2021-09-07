val = [0]*36
change = [0]*36

n = int(input())
countZero = 0
for _ in range(n):
    s = input()
    digit = 1
    for i in s[::-1]:
        if ord(i) >= ord('0') and ord(i) <= ord('9'):
            val[ord(i)-ord('0')] += (ord(i)-ord('0'))*digit
        else:
            val[ord(i)-ord('A')+10] += (ord(i)-ord('A')+10)*digit
        if ord(i) == ord('0'):
            countZero += digit
        digit *= 36
change[0] = countZero*35
for i in range(1, 35):
    change[i] = (val[i]//i)*35 - val[i]
change.sort(key=lambda x : -x)

k = int(input())
ans = sum(val)
for i in range(k):
    ans += change[i]

aa = []
while ans != 0:
    if ans % 36 >= 10:
        aa.append(chr((ans%36)-10+ord('A')))
    else:
        aa.append(chr(ord('0')+ans%36))
    ans = ans // 36
aa.reverse()

for i in aa:
    print(i,end='')
if not aa:
    print(0,end='')
print()