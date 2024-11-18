import math

def solve_equation(a, b, c):
    D = b**2 - 4*a*c
    
    if D < 0:
        return "NO SOLUTION"
    
    elif D == 0:
        x0 = -b / (2*a)
        return f"{x0:.2f}"
    
    else:
        x1 = (-b + math.sqrt(D)) / (2*a)
        x2 = (-b - math.sqrt(D)) / (2*a)
        if(x1 < x2):
            return f"{x1:.2f} {x2:.2f}"
        else:
            return f"{x2:.2f} {x1:.2f}"

x = input()
arr = x.split()
a = int(arr[0])
b = int(arr[1])
c = int(arr[2])
print(solve_equation(a,b,c))