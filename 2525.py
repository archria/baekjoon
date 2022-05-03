temp = input()

h = temp.split()[0]
m = temp.split()[1]


h = int(h)
m = int(m)
time = int(input())

timeh = time//60
timem = time - (timeh*60)

h = h + timeh
m = m + timem

if(m >= 60):
    m = m - 60
    h = h+1

if(h >= 24):
    h = h - 24

print(str(h) + ' ' + str(m))