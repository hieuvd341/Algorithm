import re
P1 = input()
P2 = input()
while True:
    try:
        line = input()
        line = line.replace(P1, P2)
        print(line)
    except EOFError:
        break
    