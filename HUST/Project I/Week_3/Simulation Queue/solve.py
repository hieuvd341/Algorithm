from collections import deque

queue = deque()

def push(value):
    queue.append(value)

def pop():
    if queue:
        print(queue.popleft())
    else:
        print("NULL")

try:
    while True:
        command = input().split()
        if command[0] == "#":
            break
        if command[0] == "PUSH":
            push(int(command[1]))
        elif command[0] == "POP":
            pop()
except (EOFError, IndexError) as e:
    pass
