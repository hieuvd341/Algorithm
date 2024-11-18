x = input()
arr = x.split()
n = int(arr[0])
k = int(arr[1])
x = input()
count =0
arr = x.split()
num_arr = []
for a in arr:
    num_arr.append(int(a))
    
sum =0
for i in range (0, k):
    sum += num_arr[i]
if sum %2 ==0:
    count +=1
for j in range (k, n):
    sum += num_arr[j]
    sum -= num_arr[j-k]
    if sum %2 ==0:
        count +=1
print(count)