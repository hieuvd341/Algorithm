n = int(input())
arr = [0]*100
arr[0] = 0
arr[1] = 1
i = 2
while i < n:
    arr[i] = arr[i-1] + arr[i-2]
    i+=1

print(arr[n-1])