n = int(input())
odd = 0
even = 0
x = input()
array = x.split()
for i in range (0,n):
    x = int(array[i])
    if x %2 ==1:
        odd+=1
    if x %2 ==0:
        even+=1
print(odd, even)