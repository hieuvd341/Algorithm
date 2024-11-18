x = int(input())
b = bin(x)
print(type(b))

b = b.replace("0b", "")
l = len(b)
res = ""

for char in b:
    # Convert char to integer, invert the bit, and convert back to char
    inverted_char = chr(ord(char) ^ 1)
    res += inverted_char

print("Original:", b)
print("Inverted:", res)
decimal_int  = int(res, 2)
print(decimal_int)