def isValid(num):
    while num != 0:
        if num%1000 == 666:
            return True
        else:
            num = num / 10
    return False

arr = [0]*10000
n = 666
i = input()
for i in range(10000):
    while isValid(n) == False:
        n += 1
    arr[i] = n
    n += 1
print(arr[i-1])
