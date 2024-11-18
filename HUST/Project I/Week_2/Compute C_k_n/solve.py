x = input()
arr = x.split()
n = int(arr[1])
k = int(arr[0])

def factorial(n):
    res = 1
    if (n == 0 or n == 1):
        return res
    else:
        for i in range(2, n + 1):
            res = res * i
        return res
    
    
num1 = factorial(k)
num2 = factorial(n)
num3 = factorial(n-k)

print((num2//(num1*num3))%(10**9+7))
