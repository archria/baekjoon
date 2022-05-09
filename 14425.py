a = input()
a = a.split()
N = int(a[0])
M = int(a[1])

target = set()
for _ in range(N):
    target.add(input())

cnt = 0

for _ in range(M):
    if input() in target:
        cnt += 1


print(cnt)