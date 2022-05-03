a = input()
a = a.split()
a.sort(reverse=True)

if(a[0] == a[1] == a[2]):
    print(10000 + int(a[0]) * 1000)
elif(a[0] == a[1]):
    print(1000 + int(a[0]) * 100)
elif(a[1] == a[2]):
    print(1000 + int(a[1]) * 100)
else:
    print(int(a[0]) * 100)