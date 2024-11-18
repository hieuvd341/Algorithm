n = int(input())
i =0
for i in range (1, 1000):
    if n *i >= 100 and n*i < 1000:
        print(n*i, end=' ')
    