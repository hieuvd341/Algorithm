with open("input.txt", "r") as fileIn:
    lines = fileIn.readlines()
    for line in lines:
        line = line.strip().split(",")
        
with open("input.txt", "r") as fileIn:
    lines = fileIn.readlines()
    for line in lines:
        for l in line:
            l = int(l)
    for line in lines:
        line = line.sort()
        print(line)        
    
        