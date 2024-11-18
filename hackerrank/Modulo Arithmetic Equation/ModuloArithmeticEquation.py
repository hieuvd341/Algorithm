<<<<<<< HEAD
def solve(N: int):
    M = 1
    res = 0
    for i in range(1, N + 1):
        M *= i
    K= M**2
    for a in range(1, K+1):  
        if res == 1000007:
            res = 0
        if K % a == 0:
            b = K // a
            if (M + a > 0) and (M + b > 0):
                res += 1
                print(f"{(M + a)} {(M + b)}")  
                
            if (M - a > 0) and (M - b > 0):
                res += 1
                print(f"{(M - a)} {(M - b)}")  
    return res 

result = solve(10)
print(result)
=======
def solve(N: int):
    M = 1
    res = 0
    for i in range(1, N + 1):
        M *= i
    K= M**2
    for a in range(1, K+1):  
        if res == 1000007:
            res = 0
        if K % a == 0:
            b = K // a
            if (M + a > 0) and (M + b > 0):
                res += 1
                print(f"{(M + a)} {(M + b)}")  
                
            if (M - a > 0) and (M - b > 0):
                res += 1
                print(f"{(M - a)} {(M - b)}")  
    return res 

result = solve(10)
print(result)
>>>>>>> bad19b40af882feab18b89e58bb73dec7250f825
