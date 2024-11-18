x =int(input())

arr = [str(i) for i in range(1,x+1)]
def permutaion(arr:list, s:str):
    if len(s.split()) == x:
        print(s)
        return
    for i in arr:
        if i in s:
            continue
        else:
            permutaion(arr, s+i+' ')

s=''
permutaion(arr, s)