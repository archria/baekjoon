num = int(input())
a = input()
a = list(map(int,a.split()))
a.sort()

list_size = int(input())
b = input()
b = list(map(int,b.split()))


def BS(target):
    left = 0
    right = num-1
    while left <= right:
        mid = (left + right) // 2
        if a[mid] == target:
            return 1
        elif a[mid] > target:
            right = mid - 1
        else:
            left = mid + 1
    return 0

for i in b:
    print(BS(i), end = " ")