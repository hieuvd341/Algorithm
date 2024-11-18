#PYTHON 
from collections import deque

def gcd(x, y):
    while y != 0:
        x, y = y, x % y
    return x

def solve(a, b, c):
    if c > max(a, b) or c % gcd(a, b) != 0:
        return -1
    
    def next_states(state):
        (jug1, jug2) = state
        states = []
        
        states.append((a, jug2))
        states.append((jug1, b))
        states.append((0, jug2))
        states.append((jug1, 0))
        pour = min(jug1, b - jug2)
        states.append((jug1 - pour, jug2 + pour))
        pour = min(jug2, a - jug1)
        states.append((jug1 + pour, jug2 - pour))
        
        return states
    
    queue = deque([((0, 0), 0)])  
    visited = set((0, 0))
    
    while queue:
        (jug1, jug2), steps = queue.popleft()
        
        if jug1 == c or jug2 == c:
            return steps
        
        for next_state in next_states((jug1, jug2)):
            if next_state not in visited:
                visited.add(next_state)
                queue.append((next_state, steps + 1))
    
    return -1

a, b, c = map(int, input().split())
print(solve(a, b, c))
