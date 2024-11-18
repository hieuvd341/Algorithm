text = input()
array = text.split("-")
if len(array[0])!=4 or len(array[1]) != 2 or len(array[2])!=2:
    print("INCORRECT")
else:
    year = int(array[0])
    month = int(array[1])
    day = int(array[2])
    if(month > 12):
        print("INCORRECT")
    elif(day>31):
        print("INCORRECT")
    else:
        print(year, month, day)