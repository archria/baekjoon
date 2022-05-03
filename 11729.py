def hanoi(num,start,aux,dest):
    if(num == 1):
        print(start, dest)
    else:
        hanoi(num-1, start, dest, aux)
        print(start, dest)
        hanoi(num-1, aux, start, dest)

sum = 1
num = int(input())

for i in range(num-1):
    sum = sum * 2 + 1
    
print(sum)
hanoi(num,1,2,3)

