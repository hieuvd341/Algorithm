x =input()
arr = x.split(":")
if len(arr[0]) ==2 and len(arr[1]) ==2 and len(arr[2]) ==2:
    if len(arr) ==3:
        h = int(arr[0])
        m = int(arr[1])
        s = int(arr[2])
        if h >=0 and h<= 23 and m >=0 and m <=59 and s >=0 and s<=59:
            print(h*3600 + m*60 + s)
        else:
            print("INCORRECT")
    else:
        print("INCORRECT")
else:
    print("INCORRECT")