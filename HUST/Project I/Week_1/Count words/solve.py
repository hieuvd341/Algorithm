#PYTHON
import re
lines = []
count = 0
while True:
    try:
        line = input()
        x = re.findall("[^ ]*", line)
        for y in x:
            if y != '' and y != '\n' and y != '\t':
                count += 1
    except EOFError:
        break


print(count)