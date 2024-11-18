stack = []

def push(value):
    stack.append(value)

def pop():
    if stack:
        print(stack.pop())
    else:
        print("NULL")


while True:
    command = input()
    if command == "#":
        break
    line = command.split()
    if line[0] == "PUSH":
        push(int(line[1]))
    elif line[0] == "POP":
        pop()