strs = set()

while True:
    line = input()
    if line == '*':
        break
    strs.add(line)  


while True:
    line = input()
    if line == '***':
        break

    cmd, key = line.split(' ', 1)  

    if cmd == "find":
        print('1' if key in strs else '0')  

    elif cmd == "insert":
        if key in strs:
            print('0')  
        else:
            strs.add(key)  
            print('1')
