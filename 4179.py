import sys
from collections import deque
read = sys.stdin.readline

R, C = map(int, read().split())
visited = [[False for _ in range(C)] for _ in range(R)]
maze = []
sy, sx = -1, -1
for y in range(R):
    maze.append(read()[:-1])
    if maze[y].find('J') != -1:


q = deque()
visited[]