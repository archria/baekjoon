num = int(input())
mylist = []
for i in range(num):
    weight, height = map(int,input().split())
    mylist.append((weight,height))

for i in mylist:
    rank = 1
    for j in mylist:
        if i[0] < j[0] and i[1] < j[1]:
            rank += 1
    print(str(rank) , end = " ")