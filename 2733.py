import sys
read = sys.stdin.readline

def get_program(ret):
    s = read()[:-1]
    ret.append(s)
    while s != "end\n":
        s = read()
        ret.append(s)
    return ret

def compiled(program, stack_info):
    # 스택에 마지막에 원소가 차 있거나
    # [와 ]의 짝이 맞지 않으면 False
    stack = []
    for i, line in enumerate(program):
        for j, cmd in enumerate(line):
            if cmd == '[':
                stack.append((i, j))
            elif cmd == ']':
                if not stack:
                    return False
                ni, nj = stack[-1]
                stack_info[(i,j)] = stack[-1]
                stack_info[(ni, nj)] = (i, j)
                stack.pop()
    if stack:
        return False
    else:
        return True

MAX = 32768
VMAX = 256
t = int(read())
for pid in range(t):
    # program의 각 문자에 2차원배열처럼 접근할 수 있음.
    program = []; stack_info = {}
    get_program(program)
    if not compiled(program, stack_info):
        print("PROGRAM #{}:\nCOMPILE ERROR".format(pid+1))
        continue

    ptr = 0
    arr = [0 for _ in range(MAX)]
    ret = []
    i = 0
    while i < len(program):
        j = 0
        while j < len(program[i]):
            cmd = program[i][j]
            if cmd == ">":
                ptr = (ptr + 1) % MAX
            elif cmd == "<":
                ptr = (ptr - 1) % MAX
            elif cmd == "+":
                arr[ptr] = (arr[ptr] + 1) % VMAX
            elif cmd == "-":
                arr[ptr] = (arr[ptr] - 1) % VMAX
            elif cmd == ".":
                ret.append(chr(arr[ptr]))
            elif cmd == "[" and arr[ptr] == 0:
                i, j = stack_info[(i, j)]
            elif cmd == "]" and arr[ptr] != 0:
                i, j = stack_info[(i, j)]
            elif cmd == "%":
                break
            j += 1
        i += 1
    print("PROGRAM #{}:\n{}".format(pid+1, ''.join(ret)))