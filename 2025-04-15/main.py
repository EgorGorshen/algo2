from collections import deque

N = int(input())
students = list(map(int, input().split()))

Q = int(input())
bilets = [int(input()) for _ in range(q)]

d = deque(students)
m = max(d)
hist = []

while d[0] != m:
    x = d.popleft()
    y = d.popleft()
    hist.append((x, y))
    if x > y:
        d.appendleft(x)
        d.append(y)
    else:
        d.appendleft(y)
        d.append(x)

d.popleft()
rest = list(d)

for k in ks:
    if k <= len(hist):
        print(*hist[k - 1])
    else:
        idx = (k - len(hist) - 1) % (N - 1)
        print(m, rest[idx])
